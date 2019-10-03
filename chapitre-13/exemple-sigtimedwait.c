// ------------------------------------------------------------------
// exemple-sigtimedwait.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main (void)
{
	sigset_t set;
	int num;
	struct timespec delay;

	fprintf(stderr, "PID=%ld\n", (long) getpid());

	/* Blocage de tous les signaux */
	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, NULL);

	/* Attente de tous les signaux pendant 10 secondes */
	delay.tv_sec = 10;
	delay.tv_nsec = 0;
	sigfillset(&set);

	while (1) {
		if ((num = sigtimedwait(&set, NULL, &delay)) < 0) {
			perror("sigtimedwait");
			break;
		}
		fprintf(stderr, "sigtimedwait: received %d\n", num);
	}
	return EXIT_SUCCESS;
}

