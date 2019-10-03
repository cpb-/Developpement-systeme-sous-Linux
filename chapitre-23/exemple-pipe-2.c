// ------------------------------------------------------------------
// exemple-pipe-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
	int pipe_fd[2];
	unsigned char buffer[256];
	int i;

	fprintf(stdout, "Creation pipe\n");
	if (pipe(pipe_fd) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	switch (fork()) {
		case -1 :
			perror("fork()");
			exit(EXIT_FAILURE);
			break;
		case 0 :
			fprintf(stdout, "Enfant : Fermeture entree\n");
			close(pipe_fd[1]);
			fprintf(stdout, "Enfant : Lecture pipe\n");
			if (read(pipe_fd[0], buffer, 256) != 256) {
				perror("read");
				exit(EXIT_FAILURE);
			}
			fprintf(stdout, "Enfant : Verification \n");
			for (i = 0; i < 256; i ++)
				if (buffer[i] != i) {
					fprintf(stdout, "Enfant : Erreur\n");
					exit(EXIT_FAILURE);
				}
			fprintf(stdout, "Enfant : Ok\n");
			break;
		default :
			fprintf(stdout, "Parent : Fermeture sortie\n");
			close(pipe_fd[0]);
			for (i = 0; i < 256; i ++)
				buffer[i] = i;
			fprintf(stdout, "Parent : Ecriture dans pipe\n");
			if (write(pipe_fd[1], buffer, 256) != 256) {
				perror("write");
				exit(EXIT_FAILURE);
			}
			wait(NULL);
			break;
	}

	return EXIT_SUCCESS;
}
