// ------------------------------------------------------------------
// exemple-scanf-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	int i;
	char c;

	i = 12345;
	printf("i = %d\n", i);
	printf("Entrez un nombre : ");
	scanf("%d", &c);
	printf("i = %d\n", i);

	return 0;
}

