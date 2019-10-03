// ------------------------------------------------------------------
// exemple-environ.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>

extern char **environ;

int main (void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i ++)
		fprintf(stdout, "%d : %s\n", i, environ[i]);

	return 0;
}
