// ------------------------------------------------------------------
// exemple-nonblock-2.c
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
	char c;

	if (pipe(pipe_fd) !=0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	switch (fork()) {
		case -1 :
			perror("fork");
			exit(EXIT_FAILURE);
		case 0 : /* fils : ecriture */
			close(pipe_fd[0]);
			while (1) {
				write(pipe_fd[1], & c, 1);
				usleep(700000);
			}
		default : /* pere : lecture */
			close(pipe_fd[1]);
			fcntl(pipe_fd[0], F_SETFL, O_NONBLOCK);
			while (1) {
				if (read(pipe_fd[0], & c, 1) == 1) 
					printf("Ok\n");
				else
					printf("Non\n");
				usleep(100000);
			}
	}

	return EXIT_SUCCESS;
}

