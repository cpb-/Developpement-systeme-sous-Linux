// ------------------------------------------------------------------
// exemple-fputs.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	int	i;

	if (argc == 1) {
		fputs("Pas d'argument\n", stdout);
	} else {
		fputs("Arguments : ", stdout);
		for (i = 1; i < argc; i ++)
			fputs(argv[i], stdout);
		fputs("\n", stdout);
	}
	return EXIT_SUCCESS;
}
