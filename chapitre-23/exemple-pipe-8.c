// ------------------------------------------------------------------
// exemple-pipe-8.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main (void)
{
	int	pipe_fd[2];
	struct stat status;

	fprintf(stdout, "Creation pipe\n");
	if (pipe(pipe_fd) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if (fstat(pipe_fd[0], & status) != 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	fprintf (stdout, "Status : ");
	if (S_ISFIFO(status.st_mode))
		fprintf(stdout, "FIFO\n");
	else
		fprintf(stdout, "? \n");

	return EXIT_SUCCESS;
}

