// ------------------------------------------------------------------
// exemple-scanf-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	int i;
	char c;

	i = 2010;
	printf("i = %d\n", i);
	printf("Entrez un nombre : ");
	scanf("%d", & c);
	printf("i = %d\n", i);

	return 0;
}
