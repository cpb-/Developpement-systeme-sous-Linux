// ------------------------------------------------------------------
// exemple-exit-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdlib.h>

void sortie (void);

int main (void)
{
	sortie();
}

void sortie (void)
{	
	exit(EXIT_FAILURE);
}
