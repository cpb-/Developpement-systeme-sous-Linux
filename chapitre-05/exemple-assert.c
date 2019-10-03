// ------------------------------------------------------------------
// exemple-assert.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void succeeding_function(int i);
void failing_function(int i);

int main(void)
{
	succeeding_function(5);
	failing_function(5);

	return EXIT_SUCCESS;
}

void succeeding_function(int num)
{
	/* Cette fonction necessite que i soit positif */
	assert(num >= 0);
	fprintf(stdout, "Ok, num est positif\n");
}

void failing_function(int num)
{
	/* Cette fonction necessite que i soit negatif */
	assert(num <= 0);
	fprintf(stdout, "Ok, num est negatif\n");
}

