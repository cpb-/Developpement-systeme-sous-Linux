// ------------------------------------------------------------------
// exemple-ctime.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
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
