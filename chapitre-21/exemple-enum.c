// ------------------------------------------------------------------
// exemple-enum.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	un, deux, trois
} enum_t;

int main (void)
{
	fprintf(stdout, "sizeof(enum_t) = %d\n", sizeof(enum_t));
	return EXIT_SUCCESS;
}
