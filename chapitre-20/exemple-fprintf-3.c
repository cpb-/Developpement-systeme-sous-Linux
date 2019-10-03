// ------------------------------------------------------------------
// exemple-fprintf-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int    d;
	double f;

	fprintf(stdout, "|  %%8.0d |  %%8.2d |  %%8.0f "
	                "|  %%8.2f |  %%8.2e |  %%8.2g |\n");
	fprintf(stdout, "+--------+--------+--------"
	                "+--------+--------+--------+\n");
	d = 0;
	f = 0.0;
	fprintf(stdout, "|%8.0d|%8.2d|%8.0f|%8.2f|%8.2e|%8.2g|\n",
	                d, d, f, f, f, f);
	d = 1;
	f = 1.0;
	fprintf(stdout, "|%8.0d|%8.2d|%8.0f|%8.2f|%8.2e|%8.2g|\n",
	                d, d, f, f, f, f);
	d = -2;
	f = -2.0;
	fprintf(stdout, "|%8.0d|%8.2d|%8.0f|%8.2f|%8.2e|%8.2g|\n",
	                d, d, f, f, f, f);
	d = 10;
	f = 10.1;
	fprintf(stdout, "|%8.0d|%8.2d|%8.0f|%8.2f|%8.2e|%8.2g|\n",
	                d, d, f, f, f, f);
	d = 100;
	f = 100.01;
	fprintf(stdout, "|%8.0d|%8.2d|%8.0f|%8.2f|%8.2e|%8.2g|\n",
	                d, d, f, f, f, f);
	return EXIT_SUCCESS;
}
