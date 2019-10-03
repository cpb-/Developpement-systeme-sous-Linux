// ------------------------------------------------------------------
// exemple-numeric.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	double d = 1234.56;

	setlocale(LC_ALL, "");
	fprintf(stdout, "%.2f\n", d);

	return EXIT_SUCCESS;
}
