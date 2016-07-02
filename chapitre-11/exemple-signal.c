// ------------------------------------------------------------------
// exemple-signal.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void gestionnaire (int numero)
{
	fprintf(stdout, "\n%ld a recu le signal %d (%s)\n", 
	        (long) getpid(), numero, sys_siglist[numero]);
}

int main (void)
{
	int i;

	for (i = 1; i < NSIG; i ++)
		if (signal(i, gestionnaire) == SIG_ERR)
			fprintf(stderr, "Signal %d non capture\n", i);

	while (1)
		pause();
}

