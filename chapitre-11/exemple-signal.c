// ------------------------------------------------------------------
// exemple-signal.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int num)
{
	fprintf(stdout, "\n%ld received signal: %d (%s)\n", 
	        (long) getpid(), num, sys_siglist[num]);
}

int main (void)
{
	int i;

	for (i = 1; i < NSIG; i ++)
		if (signal(i, signal_handler) == SIG_ERR)
			fprintf(stderr, "Signal %d not handled\n", i);

	while (1)
		pause();
}

