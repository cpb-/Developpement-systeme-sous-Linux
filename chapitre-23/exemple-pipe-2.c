// ------------------------------------------------------------------
// exemple-pipe-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
	int tube[2];
	unsigned char buffer[256];
	int i;

	fprintf(stdout, "Creation tube\n");
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
			fprintf(stdout, "Fils : Fermeture entree\n");
			close(tube[1]);
			fprintf(stdout, "Fils : Lecture tube\n");
			if (read(tube[0], buffer, 256) != 256) {
				perror("read");
				exit(EXIT_FAILURE);
			}
			fprintf(stdout, "Fils : Verification \n");
			for (i = 0; i < 256; i ++)
				if (buffer[i] != i) {
					fprintf(stdout, "Fils : Erreur\n");
					exit(EXIT_FAILURE);
				}
			fprintf(stdout, "Fils : Ok\n");
			break;
		default :
			fprintf(stdout, "Pere : Fermeture sortie\n");
			close(tube[0]);
			for (i = 0; i < 256; i ++)
				buffer[i] = i;
			fprintf(stdout, "Pere : Ecriture dans tube\n");
			if (write(tube[1], buffer, 256) != 256) {
				perror("write");
				exit(EXIT_FAILURE);
			}
			wait(NULL);
			break;
	}
	return EXIT_SUCCESS;
}
