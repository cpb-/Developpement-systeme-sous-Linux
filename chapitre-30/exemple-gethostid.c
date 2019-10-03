// ------------------------------------------------------------------
// exemple-gethostid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	fprintf(stdout, "%ld\n", gethostid());

	return EXIT_SUCCESS;
}

