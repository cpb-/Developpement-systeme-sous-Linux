// ------------------------------------------------------------------
// exemple-siginfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int num, siginfo_t *info, void *unused)
{
	fprintf(stderr, "received %d\n", num);
	if (info == NULL)
		return;
	fprintf(stderr, "  si_code   = %d\n", info->si_code);
	fprintf(stderr, "  sival_int = %d\n", info->si_value.sival_int);
}

int main (void)
{
	int   i;
	struct sigaction action;

	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigfillset(& action.sa_mask);
	fprintf(stderr, "PID=%ld\n", (long) getpid());
	for (i = 1; i < NSIG; i ++)
		if (sigaction(i, & action, NULL) < 0)
			fprintf(stderr, "%d not handled\n", i);
	while (1)
		pause();
	return EXIT_SUCCESS;
}
