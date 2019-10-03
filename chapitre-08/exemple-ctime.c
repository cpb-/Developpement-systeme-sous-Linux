// ------------------------------------------------------------------
// exemple-ctime.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	time_t t;

	t = time(NULL);
	fprintf(stdout, "%s", ctime(& t));
	return EXIT_SUCCESS;
}
