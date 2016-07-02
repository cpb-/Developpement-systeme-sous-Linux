// ------------------------------------------------------------------
// exemple-fopen.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void ouverture (char * nom, char * mode)
{
	FILE * fp;
	fprintf(stderr, "fopen(%s, %s) : ", nom, mode);
	if ((fp = fopen(nom, mode)) == NULL) {
		perror("");
	} else {
		fprintf(stderr, "Ok\n");
		fclose(fp);
	}
}

int main (void)
{
	ouverture("/etc/inittab", "r");
	ouverture("/etc/inittab", "w");
	ouverture("essai.fopen",  "r");
	ouverture("essai.fopen",  "w");
	ouverture("essai.fopen",  "r");
	return EXIT_SUCCESS;
}

