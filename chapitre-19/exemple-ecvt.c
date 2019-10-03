// ------------------------------------------------------------------
// exemple-ecvt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	double value;
	int    digits;
	int    position;
	int    sign;
	char * string;
	
	if ((argc != 3) 
	 || (sscanf(argv[1], "%lf", &value) != 1)
	 || (sscanf(argv[2], "%d", &digits) != 1)) {
		fprintf(stderr, "Syntaxe : %s value digits\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	string = ecvt(value, digits, &position, &sign);
	fprintf(stdout, "ecvt() = %s \n", string);
	fprintf(stdout, "    position = %d \n", position);
	fprintf(stdout, "    sign = %d \n", sign);

	string = fcvt(value, digits, &position, &sign);
	fprintf(stdout, "fcvt() = %s \n", string);
	fprintf(stdout, "    position = %d \n", position);
	fprintf(stdout, "    sign = %d \n", sign);

	return EXIT_SUCCESS;
}
