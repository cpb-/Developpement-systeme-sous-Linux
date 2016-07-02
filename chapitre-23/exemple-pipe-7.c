// ------------------------------------------------------------------
// exemple-pipe-7.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int  tube[2];
	char c = 'c';
	int  i;

	fprintf(stdout, "Creation tube\n");
	if (pipe(tube) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Ecriture dans tube\n");
	for (i = 0; ; i ++) {
		fprintf(stdout, "%d octets ecrits\n", i);
		if (write(tube[1], & c, 1) != 1) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
	return EXIT_SUCCESS;
}

