// ------------------------------------------------------------------
// exemple-gets.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>

int main (void)
{
	char chaine[128];

	return (gets(chaine) != NULL);
}

