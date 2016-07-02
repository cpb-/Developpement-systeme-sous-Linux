// ------------------------------------------------------------------
// exemple-system-shell.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	char ligne[MAX_CANON];
	while (1) {
		fprintf(stderr, "-> ");
		if (fgets(ligne, MAX_CANON, stdin) == NULL)
			break;
		system(ligne);
	}
	return 0;
}

