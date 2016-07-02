// ------------------------------------------------------------------
// exemple-puts.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv [])
{
	int	i;
	if (argc == 1) {
		puts("Pas d'argument\n");
	} else {
		puts("Arguments : ");
		for (i = 1; i < argc; i ++)
			puts(argv[i]);
		puts("\n");
	}
	return EXIT_SUCCESS;
}
