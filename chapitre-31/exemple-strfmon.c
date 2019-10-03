// ------------------------------------------------------------------
// exemple-strfmon.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <locale.h>
#include <monetary.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	double d;
	char   buffer[80];

	setlocale(LC_ALL, "");
	if ((argc != 3) 
	 || (sscanf(argv[2], "%lf", & d) != 1)) {
		fprintf(stderr, "%s format valeur \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (strfmon(buffer, 80, argv[1], d) >0)
		fprintf(stdout, "%s\n", buffer);

	return EXIT_SUCCESS;
}
