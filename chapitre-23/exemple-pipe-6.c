// ------------------------------------------------------------------
// exemple-pipe-6.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
	int    pipe_fd[2];
	char  *buffer = "AZERTYUIOP";

	signal(SIGPIPE, SIG_IGN);	
	fprintf(stdout, "Creation pipe\n");
	if (pipe(pipe_fd) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Fermeture sortie\n");
	close(pipe_fd[0]);
	fprintf(stdout, "Ecriture dans pipe\n");
	if (write(pipe_fd[1], buffer, strlen(buffer)) != strlen(buffer)) {
		perror("write");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Fin du programme\n");

	return EXIT_SUCCESS;
}
