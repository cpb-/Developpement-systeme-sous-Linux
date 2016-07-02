// ------------------------------------------------------------------
// exemple-tzname.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
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
