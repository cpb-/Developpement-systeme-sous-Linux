// ------------------------------------------------------------------
// taille-off-t.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

//#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf("sizeof(off_t) = %lu\n", sizeof(off_t));

	return EXIT_SUCCESS;
}
