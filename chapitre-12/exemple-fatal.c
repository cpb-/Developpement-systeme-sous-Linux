// ------------------------------------------------------------------
// exemple-fatal.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void gestionnaire_signal_fatal (int numero)
{
	/* Effectuer le nettoyage :			*/
	/*   Couper proprement les connexions reseau	*/
	/*   Supprimer les fichiers de verrouillage	*/
	/*   Tuer eventuellement les processus fils	*/

	fprintf(stdout, "\nJe fais le menage !\n");
	fflush(stdout);
	signal(numero, SIG_DFL);
	raise(numero);
}

int main (void)
{
	struct sigaction action;
	action.sa_handler = gestionnaire_signal_fatal;
	action.sa_flags = 0;
	sigfillset(& action.sa_mask);
	fprintf(stdout, "mon pid est %ld\n", (long) getpid());
	if ((sigaction(SIGTERM, & action, NULL) != 0)
	 || (sigaction(SIGSEGV, & action, NULL) != 0)) {
	 	perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return EXIT_SUCCESS;
}

