// ------------------------------------------------------------------
// exemple-sigaction-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int unused)
{
}

int main (void)
{
	struct sigaction action;

	signal(SIGUSR1, signal_handler);
	sigaction(SIGUSR1, NULL, &action);
	
	if (action.sa_handler == signal_handler)
		fprintf(stdout, "same address\n");
	else
		fprintf(stdout, "different address\n");

	return EXIT_SUCCESS;
}
