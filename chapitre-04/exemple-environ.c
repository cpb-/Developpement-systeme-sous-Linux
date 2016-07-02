// ------------------------------------------------------------------
// exemple-environ.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>

extern char ** environ;

int main (void)
{
	int	i = 0;

	for (i = 0; environ[i] != NULL; i ++)
		fprintf(stdout, "%d : %s\n", i, environ[i]);

	return 0;
}
