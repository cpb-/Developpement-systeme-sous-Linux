// ------------------------------------------------------------------
// exemple-strsignal.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
	int i;

	fprintf(stdout, "strsignal() :\n");
	for (i = 1; i < NSIG; i ++)
		fprintf(stdout, "%s\n", strsignal(i));

	fprintf (stdout, "\nsys_siglist[] : \n");
	for (i = 1; i < NSIG; i ++)
		fprintf(stdout, "%d : %s\n", i, sys_siglist[i]);

	return EXIT_SUCCESS;
}

