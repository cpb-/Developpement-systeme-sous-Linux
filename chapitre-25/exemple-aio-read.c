// ------------------------------------------------------------------
// exemple-aio-read.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>

#define SIGNAL_IO	(SIGRTMIN + 3)

void signal_handler(int signum, siginfo_t * info, void * vide)
{
	struct aiocb * cb;
	ssize_t        bytes;

	if (info->si_code == SI_ASYNCIO) {
		cb = info->si_value.sival_ptr;
		if (aio_error(cb) == EINPROGRESS)
			return;
		bytes = aio_return(cb);
		fprintf(stdout, "Lecture 1 : %ld octets lus \n", bytes);
	}
}

void thread(sigval_t value)
{
	struct aiocb * cb;
	ssize_t       bytes;
	cb = value.sival_ptr;
	if (aio_error(cb) == EINPROGRESS)
		return;
	bytes = aio_return(cb);
	fprintf(stdout, "Lecture 2 : %ld octets lus \n", bytes);
}


int main(int argc, char * argv[])
{
	int              fd;
	struct aiocb     cb[3];
	char             buffer[256][3];
	struct sigaction action;
	int              bytes;

	if (argc != 2) {
		fprintf (stderr, "Syntaxe : %s fichier\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	action.sa_sigaction = signal_handler;
	action.sa_flags     = SA_SIGINFO;
	sigemptyset(& action.sa_mask);
	if (sigaction(SIGNAL_IO, & action, NULL) < 0) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	// Lecture 0 :  Pas de notification
	cb[0].aio_fildes   = fd;
	cb[0].aio_offset   = 0;
	cb[0].aio_buf      = buffer[0];
	cb[0].aio_nbytes   = 256;
	cb[0].aio_reqprio  = 0;
	cb[0].aio_sigevent.sigev_notify = SIGEV_NONE;

	// Lecture 1 : Notification par signal
	cb[1].aio_fildes   = fd;
	cb[1].aio_offset   = 0;
	cb[1].aio_buf      = buffer [1];
	cb[1].aio_nbytes   = 256;
	cb[1].aio_reqprio  = 0;
	cb[1].aio_sigevent.sigev_notify = SIGEV_SIGNAL;
	cb[1].aio_sigevent.sigev_signo  = SIGNAL_IO;
	cb[1].aio_sigevent.sigev_value.sival_ptr = & cb[1];
	
	// Lecture 2 : Notification par thread
	cb[2].aio_fildes   = fd;
	cb[2].aio_offset   = 0;
	cb[2].aio_buf      = buffer [2];
	cb[2].aio_nbytes   = 256;
	cb[2].aio_reqprio  = 0;
	cb[2].aio_sigevent.sigev_notify = SIGEV_THREAD;
	cb[2].aio_sigevent.sigev_notify_function   = thread;
	cb[2].aio_sigevent.sigev_notify_attributes = NULL;
	cb[2].aio_sigevent.sigev_value.sival_ptr = & cb[2];

	// Lancement des lectures
	if ((aio_read (& cb[0]) < 0) 
	 || (aio_read (& cb[1]) < 0) 
	 || (aio_read (& cb[2]) < 0)) {
		perror("aio_read");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Lectures lancees\n");
	while ((aio_error(& cb[0]) == EINPROGRESS)
	    || (aio_error(& cb[1]) == EINPROGRESS)		
	    || (aio_error(& cb[2]) == EINPROGRESS))
		sleep(1);
	bytes = aio_return(& cb[0]);
	fprintf(stdout, "Lecture O : %d octets lus \n", bytes);
	return EXIT_SUCCESS;
}

