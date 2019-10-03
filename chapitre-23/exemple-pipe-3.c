// ------------------------------------------------------------------
// exemple-pipe-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	int	pipe_fd[2];

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s commande_1 commande_2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

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
			close(pipe_fd[0]);
			dup2(pipe_fd[1], STDOUT_FILENO);
			system(argv[1]);
			break;
		default :
			close(pipe_fd[1]);
			dup2(pipe_fd[0], STDIN_FILENO);
			system(argv[2]);
			break;
	}

	return EXIT_SUCCESS;
}

