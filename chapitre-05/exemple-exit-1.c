// ------------------------------------------------------------------
// exemple-exit-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdlib.h>

void quit(void);

int main (void)
{
	quit();
}

void quit(void)
{	
	exit(EXIT_FAILURE);
}
