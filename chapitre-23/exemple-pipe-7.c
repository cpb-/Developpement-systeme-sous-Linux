// ------------------------------------------------------------------
// exemple-pipe-7.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int  pipe_fd[2];
	char c = 'c';
	int  i;

	fprintf(stdout, "Creation pipe\n");
	if (pipe(pipe_fd) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Ecriture dans pipe\n");
	for (i = 0; ; i ++) {
		fprintf(stdout, "%d octets ecrits\n", i);
		if (write(pipe_fd[1], & c, 1) != 1) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	return EXIT_SUCCESS;
}

