// ------------------------------------------------------------------
// exemple-numeric.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	double d = 2010.08;
	setlocale(LC_ALL, "");
	fprintf(stdout, "%.2f\n", d);
	return EXIT_SUCCESS;
}
