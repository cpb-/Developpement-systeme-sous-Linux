// ------------------------------------------------------------------
// exemple-nonblock-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int  pipe_fd[2];
	char c = 'c';
	int  i;

	if (pipe(pipe_fd) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	fcntl(pipe_fd[1], F_SETFL, O_NONBLOCK);
	i = 0;
	while (1) {
		if (write(pipe_fd[1], & c, 1) != 1) {
			perror("write");
			sleep(1);
		} else
			i ++;
		fprintf(stdout, "%d octets ecrits\n", i);
	}

	return EXIT_SUCCESS;
}
