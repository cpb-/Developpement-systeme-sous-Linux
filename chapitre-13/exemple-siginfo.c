// ------------------------------------------------------------------
// exemple-siginfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gestionnaire (int numero, siginfo_t * info, void * inutilise)
{
	fprintf(stderr, "Recu %d\n", numero);
	if (info == NULL)
		return;
	fprintf(stderr, "  si_code   = %d\n", info->si_code);
	fprintf(stderr, "  sival_int = %d\n", info->si_value.sival_int);
}

int main (void)
{
	int   i;
	struct sigaction action;

	action.sa_sigaction = gestionnaire;
	action.sa_flags = SA_SIGINFO;
	sigfillset(& action.sa_mask);
	fprintf(stderr, "PID=%ld\n", (long) getpid());
	for (i = 1; i < NSIG; i ++)
		if (sigaction(i, & action, NULL) < 0)
			fprintf(stderr, "%d non intercepte\n", i);
	while (1)
		pause();
	return EXIT_SUCCESS;
}
