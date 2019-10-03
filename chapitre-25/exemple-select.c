// ------------------------------------------------------------------
// exemple-select.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define	CHILDS	10

int main (void)
{
	int pipe_fd[CHILDS][2];
	int i;
	int max = -1;
	char c;
	fd_set set;

	for (i = 0; i < CHILDS; i ++) {
		if (pipe (pipe_fd[i]) < 0) {
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		if (fork() == 0) {
			// Enfant
			close(pipe_fd[i][0]);
			c = '0' + i;
			while(1) {
				sleep(i + 1);
				write(pipe_fd[i][1], & c, 1);
			}
		}
		close(pipe_fd[i][1]);
	}
	// Parent
	while (1) {
		FD_ZERO(& set);
		for (i = 0; i < CHILDS; i ++) {
			FD_SET(pipe_fd[i][0], & set);
			if (pipe_fd[i][0] > max)
				max = pipe_fd[i][0];
		}
		if (select(max, & set, NULL, NULL, NULL) <= 0) {
			perror("select");
			break;
		}
		for (i = 0; i < CHILDS; i ++) {
		 	if (FD_ISSET(pipe_fd[i][0], & set)) {
				read(pipe_fd[i][0], & c, 1);
				fprintf(stderr, "%d ", i);
			}
		}
	}
	return EXIT_SUCCESS;
}

