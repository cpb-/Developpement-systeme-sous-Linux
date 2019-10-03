// ------------------------------------------------------------------
// exemple-sizeof.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf("sizeof(char)          = %lu\n", sizeof(char));
	printf("sizeof(short int)     = %lu\n", sizeof(short int));
	printf("sizeof(int)           = %lu\n", sizeof(int));
	printf("sizeof(long int)      = %lu\n", sizeof(long int));
	printf("sizeof(long long int) = %lu\n", sizeof(long long int));
	printf("sizeof(float)         = %lu\n", sizeof(float));
	printf("sizeof(double)        = %lu\n", sizeof(double));
	printf("sizeof(long double)   = %lu\n", sizeof(long double));
	printf("sizeof(void *)        = %lu\n", sizeof(void *));

	return EXIT_SUCCESS;
}

