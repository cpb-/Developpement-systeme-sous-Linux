// ------------------------------------------------------------------
// exemple-argv.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>

int main (int argc, char * argv[])
{
	int	i;

	fprintf(stdout, "%s a recu en argument :\n", argv[0]);
	for (i = 1; i < argc; i ++)
		fprintf(stdout, "  %s\n", argv[i]);
	return 0;
}
