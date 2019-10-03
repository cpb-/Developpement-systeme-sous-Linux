// ------------------------------------------------------------------
// exemple-system-shell.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	char string[MAX_CANON];

	while (1) {
		fprintf(stderr, "-> ");
		if (fgets(string, MAX_CANON, stdin) == NULL)
			break;
		system(string);
	}

	return 0;
}

