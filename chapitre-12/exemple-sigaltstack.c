// ------------------------------------------------------------------
// exemple-sigaltstack.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void gestionnaire (int numero)
{
	stack_t pile;

	fprintf(stdout, "\nSignal %d recu\n", numero);

	if (sigaltstack(NULL, & pile) != 0) {
		fprintf(stderr, "Erreur sigaltstack %d\n", errno);
		return;
	}
	if (pile.ss_flags & SS_DISABLE)
		fprintf(stdout, "La pile speciale est inactive\n");
	else
		fprintf(stdout, "La pile speciale est active\n");

	if (pile.ss_flags & SS_ONSTACK)
		fprintf(stdout, "La pile speciale est en cours d'utilisation\n");
	else
		fprintf(stdout, "La pile speciale n'est pas utilisee actuellement\n");
}

int main (void)
{
	stack_t pile;
	struct sigaction action;
	
	if ((pile.ss_sp = malloc(SIGSTKSZ)) == NULL) {
		fprintf(stderr, "Pas assez de memoire\n");
		exit(EXIT_FAILURE);
	}
	pile.ss_size = SIGSTKSZ;
	pile.ss_flags = 0;

	if (sigaltstack(& pile, NULL) != 0) {
		fprintf(stderr, "Erreur sigaltstack() %d\n", errno);
		exit(EXIT_FAILURE);
	}

	action.sa_handler = gestionnaire;
	sigemptyset(& (action.sa_mask));
	action.sa_flags = SA_RESTART | SA_ONSTACK;
	if (sigaction(SIGQUIT, & action, NULL) != 0) {
		fprintf(stderr, "Erreur sigaction() %d \n", errno);
		exit(EXIT_FAILURE);
	}

	action.sa_handler = gestionnaire;
	sigemptyset(& (action.sa_mask));
	action.sa_flags = SA_RESTART;
	if (sigaction(SIGTERM, & action, NULL) != 0) {
		fprintf(stderr, "Erreur sigaction() %d \n", errno);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "PID = %ld\n", (long) getpid());
	fflush(stdout);

	while (1)
		pause();

	return EXIT_SUCCESS;
}

