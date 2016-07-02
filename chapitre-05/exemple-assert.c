// ------------------------------------------------------------------
// exemple-assert.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void fonction_reussissant (int i);
void fonction_echouant    (int i);

int main (void)
{
	fonction_reussissant(5);
	fonction_echouant(5);

	return EXIT_SUCCESS;
}

void fonction_reussissant (int i)
{
	/* Cette fonction necessite que i soit positif */
	assert(i >= 0);
	fprintf(stdout, "Ok, i est positif\n");
}

void fonction_echouant (int i)
{
	/* Cette fonction necessite que i soit négatif */
	assert(i <= 0);
	fprintf(stdout, "Ok, i est negatif\n");
}

