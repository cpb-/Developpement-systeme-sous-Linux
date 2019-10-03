// ------------------------------------------------------------------
// exemple-fgets.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * alloc_fgets(FILE *fp);

int main (void)
{
	char *string;

	for (;;) {
		string = alloc_fgets(stdin);
		if (string == NULL)
			// Pas assez de memoire
			break;

		if ((string[0] == '\n') || (string[0] == '\0'))
			// Chaine vide... on quitte
			break;

		fprintf(stdout, "%lu caracteres\n", strlen(string));
		free(string);
	}
	return EXIT_SUCCESS;
}


#define ALLOC_STEP 64

char * alloc_fgets (FILE * fp)
{
	char *string = NULL;
	char *new_string = NULL;
	char *start  = NULL;
	int   size = 0;

	for (;;) {
		new_string  = realloc(string, size + ALLOC_STEP);
		if (new_string == NULL)
			break;
		string = new_string;
		start = &(string[size]);
		size += ALLOC_STEP - 1;
		if (fgets(start, ALLOC_STEP, fp) == NULL)
			break;
		if (strlen(start) < ALLOC_STEP - 1)
			break;
	}
	return string;
}

