// ------------------------------------------------------------------
// taille-off-t.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

//#define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf("sizeof(off_t) = %d\n", sizeof(off_t));
	return EXIT_SUCCESS;
}
