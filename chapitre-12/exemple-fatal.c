// ------------------------------------------------------------------
// exemple-fatal.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void signal_handler(int num)
{
	/* Effectuer le nettoyage :			*/
	/*   Couper proprement les connexions reseau	*/
	/*   Supprimer les fichiers de verrouillage	*/
	/*   Tuer eventuellement les processus fils	*/

	fprintf(stdout, "\nJe fais le menage !\n");
	fflush(stdout);
	signal(num, SIG_DFL);
	raise(num);
}

int main (void)
{
	struct sigaction action
	;
	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	sigfillset(& action.sa_mask);
	fprintf(stdout, "My PID %ld\n", (long) getpid());
	if ((sigaction(SIGTERM, & action, NULL) != 0)
	 || (sigaction(SIGSEGV, & action, NULL) != 0)) {
	 	perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return EXIT_SUCCESS;
}

