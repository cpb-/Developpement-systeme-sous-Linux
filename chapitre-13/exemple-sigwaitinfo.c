// ------------------------------------------------------------------
// exemple-sigwaitinfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int num, siginfo_t * info, void *unused)
{
	fprintf(stderr, "handler: received %d\n", num);
}

int main (void)
{
	sigset_t set;
	int num;
	struct sigaction action;

	fprintf(stderr, "PID=%ld\n", (long) getpid());

	/* Installation gestionnaire pour SIGRTMIN+1 */
	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(& action.sa_mask);
	sigaction(SIGRTMIN + 1, &action, NULL);

	/* Blocage de tous les signaux sauf SIGRTMIN+1 */
	sigfillset(&set);
	sigdelset(&set, SIGRTMIN + 1);
	sigprocmask(SIG_BLOCK, &set, NULL);

	/* Attente de tous les signaux sauf RTMIN+1 */
	sigfillset(&set);
	sigdelset(&set, SIGRTMIN + 1);

	while (1) {
		if ((num = sigwaitinfo(&set, NULL)) < 0)
			perror("sigwaitinfo");
		else
			fprintf(stderr, "sigwaitinfo : received %d\n", num);
	}
	return EXIT_SUCCESS;
}

