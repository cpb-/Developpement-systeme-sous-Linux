// ------------------------------------------------------------------
// exemple-sys-errlist.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

	int
main (void)
{
	int i;
	for (i = 0; i < sys_nerr; i++)
		if (sys_errlist[i] != NULL)
			fprintf(stdout, "%d : %s\n", i, sys_errlist[i]);
		else
			fprintf(stdout, "** Pas de message pour %d **\n", i);
	return EXIT_SUCCESS;
}
