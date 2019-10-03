// ------------------------------------------------------------------
// exemple-atexit.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void out_1(void);
void out_2(void);
void out_3(void);

int main(void)
{
	if (atexit(out_3) != 0)
		fprintf(stderr, "Unable to record out_1()\n");
	if (atexit(out_2) != 0)
		fprintf(stderr, "Unable to record out_2()\n");
	if (atexit(out_2) != 0)
		fprintf(stderr, "Unable to record out_2()\n");
	if (atexit(out_1) != 0)
		fprintf(stderr, "Unable to record out_1()\n");

	fprintf(stdout, "Ok, returning from main()\n");

	return EXIT_SUCCESS;
}


void out_1(void)
{
	fprintf(stdout, "out_1(): calling exit()\n");
	exit(EXIT_SUCCESS);
}

void out_2(void)
{
	fprintf(stdout, "out_2()\n");
}

void out_3(void)
{
	fprintf(stdout, "out_3()\n");
}

