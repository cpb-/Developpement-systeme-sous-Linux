// ------------------------------------------------------------------
// exemple-strcasestr.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
	int	  i;
	char *string;

	setlocale(LC_ALL, "");
	if (argc != 3) {
		fprintf (stderr, "Usage: %s string sub-string\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (strlen(argv[2]) == 0) {
		fprintf(stderr, "Empty sub-string!\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	string = argv[1];
	while (1) {
		string = strcasestr(string, argv[2]);
		if (string == NULL)
			break;
		/* on saute la sous-chaine trouvee */
		string += strlen(argv[2]);
		i ++;
	}
	if (i == 0)
		fprintf(stdout, "%s not found in %s\n",
				argv[2], argv[1]);
	else
		fprintf(stdout, "%s found %d times in %s\n",
				argv[2], i, argv[1]);

	return EXIT_SUCCESS;
}

