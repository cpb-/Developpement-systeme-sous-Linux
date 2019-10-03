// ------------------------------------------------------------------
// exemple-sigpending.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

void signal_handler(int num)
{
	fprintf(stdout, "received %d (%s)\n", num, sys_siglist[num]);
}

int main (void)
{
	int i;
	struct sigaction action;
	sigset_t set;

	action.sa_handler = signal_handler;
	sigfillset (&(action.sa_mask));
	action.sa_flags = 0; /* Pas de SA_RESTART */
	for (i = 1; i < NSIG; i ++)
		if (sigaction(i, &action, NULL) != 0)
			fprintf(stderr, "%ld : %d not handled\n",
					(long) getpid(), i);

	/* On bloque tout sauf SIGINT */
	sigfillset(&set);
	sigdelset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL);

	/* un appel systeme bloque */
	read(0, &i, sizeof(int));

	/* Voyons maintenant qui est en attente */
	sigpending(&set);
	for (i = 1; i < SIGRTMIN; i ++)
		if (sigismember(&set, i))
			fprintf(stdout, "%d (%s) is waiting\n", 
				i, sys_siglist[i]);

	/* On debloque tous les signaux pour les voir arriver */
	sigemptyset(&set);
	sigprocmask(SIG_SETMASK, &set, NULL);

	return EXIT_SUCCESS;
}

