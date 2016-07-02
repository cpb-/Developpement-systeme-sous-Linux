// ------------------------------------------------------------------
// exemple-sigtimedwait.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main (void)
{
	sigset_t         ensemble;
	int              numero;
	struct timespec  delai;

	fprintf(stderr, "PID=%ld\n", (long) getpid());

	/* Blocage de tous les signaux */
	sigfillset(& ensemble);
	sigprocmask(SIG_BLOCK, & ensemble, NULL);

	/* Attente de tous les signaux pendant 10 secondes */
	delai.tv_sec = 10;
	delai.tv_nsec = 0;
	sigfillset(& ensemble);

	while (1) {
		if ((numero = sigtimedwait(& ensemble, NULL, & delai)) < 0) {
			perror("sigtimedwait");
			break;
		}
		fprintf(stderr, "sigtimedwait : %d recu \n", numero);
	}
	return EXIT_SUCCESS;
}

