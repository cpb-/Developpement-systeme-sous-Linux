// ------------------------------------------------------------------
// exemple-stdarg.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	fprintf(stderr, "sizeof(uint8_t)  = %lu\n",  sizeof(uint8_t));
	fprintf(stderr, "sizeof(int16_t)  = %lu\n",  sizeof(int16_t));
	fprintf(stderr, "sizeof(uint32_t) = %lu\n",  sizeof(uint32_t));
	fprintf(stderr, "sizeof(int64_t)  = %lu\n",  sizeof(int64_t));

	return EXIT_SUCCESS;
}

