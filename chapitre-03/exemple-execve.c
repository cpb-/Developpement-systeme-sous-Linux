// ------------------------------------------------------------------
// exemple-execve.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern char ** environ;

int main (void)
{
	char * argv[] = {"sh", "-c", "echo $SHLVL", (char *) NULL };

	fprintf(stdout, "Je lance /bin/sh -c \"echo $SHLVL\" :\n");

	execve("/bin/sh", argv, environ);

	fprintf(stdout, "Echec : erreur = %d\n", errno);
	return 0;
}


