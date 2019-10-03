// ------------------------------------------------------------------
// exemple-fopen.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void open_file(char *name, char *mode)
{
	FILE *fp;

	fprintf(stderr, "fopen(%s, %s) : ", name, mode);
	if ((fp = fopen(name, mode)) == NULL) {
		perror("");
	} else {
		fprintf(stderr, "Ok\n");
		fclose(fp);
	}
}

int main (void)
{
	open_file("/etc/passwd", "r");
	open_file("/etc/passwd", "w");
	open_file("essai.fopen",  "r");
	open_file("essai.fopen",  "w");
	open_file("essai.fopen",  "r");

	return EXIT_SUCCESS;
}

