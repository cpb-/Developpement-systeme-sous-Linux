// ------------------------------------------------------------------
// exemple-pipe-5.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
	int    tube[2];
	char *  buffer = "AZERTYUIOP";
	
	fprintf(stdout, "Creation tube\n");
	if (pipe(tube) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Fermeture sortie\n");
	close(tube[0]);
	fprintf(stdout, "Ecriture dans tube\n");
	if (write(tube[1], buffer, strlen(buffer)) != strlen(buffer)) {
		perror("write");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Fin du programme\n");
	return EXIT_SUCCESS;
}
