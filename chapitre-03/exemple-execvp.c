// ------------------------------------------------------------------
// exemple-execvp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main (void)
{
	char * argv[] = { "ls", "-l", "-n", (char *) NULL };

	execvp("ls", argv);

	fprintf(stderr, "Erreur %d\n", errno);
	return 1;
}

