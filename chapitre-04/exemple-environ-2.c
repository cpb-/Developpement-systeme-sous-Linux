// ------------------------------------------------------------------
// exemple-environ-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>

int main (int argc, char *argv[], char *envp[])
{
	int i = 0;

	for (i = 0; envp[i] != NULL; i ++)
		fprintf(stdout, "%d : %s\n", i, envp[i]);

	return 0;
}
