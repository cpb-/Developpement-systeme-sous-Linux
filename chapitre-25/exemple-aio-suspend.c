// ------------------------------------------------------------------
// exemple-aio-suspend.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define NB_OP	10

int main (int argc, char * argv[])
{
	int              fd;
	int              i;
	struct aiocb     cb[NB_OP];
	char             buffer[256][NB_OP];

	struct sigevent  lio_sigev;
	struct aiocb *   lio[NB_OP];

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s fichier\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < NB_OP; i ++) {
		cb[i].aio_fildes   = fd;
		cb[i].aio_offset   = 0;
		cb[i].aio_buf      = buffer[i];
		cb[i].aio_nbytes   = 256;
		cb[i].aio_reqprio  = i;
		cb[i].aio_lio_opcode = LIO_READ;
		cb[i].aio_sigevent.sigev_notify = SIGEV_NONE;
		lio[i] = & cb[i];
	}

	lio_sigev.sigev_notify = SIGEV_NONE;
	if (lio_listio(LIO_NOWAIT, lio, NB_OP, & lio_sigev) < 0) {
		perror("lio_listio");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Lectures lancees\n");

	while (1) {
		for (i = 0; i < NB_OP; i ++)
			if (lio[i] != NULL)
				break;
		if (i == NB_OP)
			// Toutes les operations sont finies
			break;
		if (aio_suspend((const struct aiocb **) lio, NB_OP, NULL) == 0) {
			for (i = 0; i < NB_OP; i ++)
				if (lio[i] != NULL)
					if (aio_error(lio[i]) != EINPROGRESS) {
						fprintf(stdout, "Lecture %d : %ld octets \n",
								i, aio_return(lio[i]));
						lio[i] = NULL;
					}
		}
	}
	return EXIT_SUCCESS;
}

