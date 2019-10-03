// ------------------------------------------------------------------
// exemple-tzname.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	tzset ();
	fprintf(stdout, "tzname[0] = %s\n", tzname[0]);
	fprintf(stdout, "tzname[1] = %s\n", tzname[1]);
	return EXIT_SUCCESS;
}
