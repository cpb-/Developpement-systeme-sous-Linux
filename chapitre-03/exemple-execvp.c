// ------------------------------------------------------------------
// exemple-execvp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main (void)
{
	char * argv[] = { "ls", "-l", "-n", (char *) NULL };

	execvp("ls", argv);

	fprintf(stderr, "Error %d\n", errno);
	return 1;
}

