// ------------------------------------------------------------------
// exemple-sigwaitinfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void gestionnaire (int numero, siginfo_t * info, void * inutile)
{
	fprintf(stderr, "gestionnaire : %d recu \n", numero);
}

int main (void)
{
	sigset_t         ensemble;
	int              numero;
	struct sigaction action;

	fprintf(stderr, "PID=%ld\n", (long) getpid());

	/* Installation gestionnaire pour SIGRTMIN+1 */
	action.sa_sigaction = gestionnaire;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(& action. sa_mask);
	sigaction(SIGRTMIN + 1, & action, NULL);

	/* Blocage de tous les signaux sauf SIGRTMIN+1 */
	sigfillset(& ensemble);
	sigdelset(& ensemble, SIGRTMIN + 1);
	sigprocmask(SIG_BLOCK, & ensemble, NULL);

	/* Attente de tous les signaux sauf RTMIN+1 */
	sigfillset(& ensemble);
	sigdelset(& ensemble, SIGRTMIN + 1);

	while (1) {
		if ((numero = sigwaitinfo(& ensemble, NULL)) < 0)
			perror("sigwaitinfo");
		else
			fprintf(stderr, "sigwaitinfo : %d recu\n", numero);
	}
	return EXIT_SUCCESS;
}

