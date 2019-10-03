// ------------------------------------------------------------------
// exemple-mmap-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int *int_ptr;

void signal_hander(int num)
{
	fprintf(stdout, "Child: *int_ptr = %d\n", *int_ptr);
	fflush(stdout);
}

int main (void)
{
	char   filename[7] = "XXXXXX";
	int    fd;
	pid_t  pid;

	if (signal(SIGUSR1, signal_hander) == SIG_ERR) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
	if ((fd = mkstemp(filename)) < 0) {
		perror("mkstemp");
		exit(EXIT_FAILURE);
	}
	if (write(fd, &fd, sizeof (int)) != sizeof (int)) {
		perror("write");
		exit(EXIT_FAILURE);
	}
	int_ptr = (int *) mmap(NULL, sizeof (int),
	                      PROT_READ | PROT_WRITE, MAP_SHARED,
	                      fd, 0);
	if (int_ptr == (int *) MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	close(fd);
	unlink(filename);

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		while (1)
			sleep(1);
	} else {
		for ((*int_ptr) = 0; (*int_ptr) < 10; (*int_ptr) ++) {
			fprintf(stdout, "Parent: *int_ptr = %d\n", *int_ptr);
			fflush(stdout);
			kill(pid, SIGUSR1);
			sleep(1);
		}
		/* Ne pas oublier de tuer le processus enfant en attente */
		kill(pid, SIGKILL);
	}
	return EXIT_SUCCESS;
}

