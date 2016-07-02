// ------------------------------------------------------------------
// exemple-signal-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void gestionnaire (int numero)
{
	fprintf(stdout, "\n%ld a recu le signal %d\n", 
	        (long) getpid(), numero);
}

int main (void)
{
	int i;

	for (i = 1; i < _NSIG; i ++)
		if (signal(i, gestionnaire) == SIG_ERR)
			fprintf(stderr, "Signal %d non capture\n", i);

	while (1)
		pause();
}

