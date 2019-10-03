// ------------------------------------------------------------------
// exemple-execve.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern char ** environ;

int main (void)
{
	char * argv[] = {"bash", "-c", "echo $SHLVL", (char *) NULL };

	fprintf(stdout, "Je lance /bin/bash -c \"echo $SHLVL\" :\n");

	execve("/bin/bash", argv, environ);

	fprintf(stdout, "Echec : erreur = %d\n", errno);
	return 0;
}


