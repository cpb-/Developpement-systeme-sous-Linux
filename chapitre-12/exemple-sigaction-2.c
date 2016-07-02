// ------------------------------------------------------------------
// exemple-sigaction-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

int main (void)
{
	int i;
	struct sigaction action;
	for (i = 1; i < NSIG; i ++) {
		if (sigaction(i, NULL, & action) != 0)
			fprintf(stderr, "%d : Erreur\n", i);
		if (action.sa_handler != SIG_DFL) {
			fprintf(stdout, "%d (%s) : ",
				i, sys_siglist[i]);
			if (action.sa_handler == SIG_IGN)
				fprintf(stdout, "ignore\n");
			else
				fprintf(stdout, "personnalise\n");
		}
	}
	return EXIT_SUCCESS;
}
