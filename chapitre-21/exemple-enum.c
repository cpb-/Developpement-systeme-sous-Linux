// ------------------------------------------------------------------
// exemple-enum.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	one, two, three
} enum_t;

int main (void)
{
	fprintf(stdout, "sizeof(enum_t) = %lu\n", sizeof(enum_t));

	return EXIT_SUCCESS;
}
