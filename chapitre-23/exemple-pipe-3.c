// ------------------------------------------------------------------
// exemple-pipe-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	int	tube[2];

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s commande_1 commande_2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (pipe(tube) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	switch (fork()) {
		case -1 :
			perror("fork()");
			exit(EXIT_FAILURE);
			break;
		case 0 :
			close(tube[0]);
			dup2(tube[1], STDOUT_FILENO);
			system(argv[1]);
			break;
		default :
			close(tube[1]);
			dup2(tube[0], STDIN_FILENO);
			system(argv[2]);
			break;
	}
	return EXIT_SUCCESS;
}

