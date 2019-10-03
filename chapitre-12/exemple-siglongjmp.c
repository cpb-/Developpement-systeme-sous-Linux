// ------------------------------------------------------------------
// exemple-siglongjmp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

sigjmp_buf	context;

void signal_handler(int num)
{
	siglongjmp(context, 1);
	/* Si l'on est ici le saut a rate, il faut quitter */
	signal(num, SIG_DFL);
	raise(num);
}

int main (void)
{
	int p, q, r;

	struct sigaction action;

	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	sigfillset(& action.sa_mask);
	sigaction(SIGFPE, & action, NULL);

	while (1) {
		if (sigsetjmp(context, 1) != 0) {
			/* On est arrive ici par siglongjmp() */
			fprintf(stdout, "Aie ! erreur mathematique ! \n");
			fflush(stdout);
		}
		while (1) {
			fprintf(stdout, "Entrez le dividende p : ");
			if (fscanf(stdin, "%d", & p) == 1)
				break;
		}
		while (1) {
			fprintf(stdout, "Entrez le diviseur q : ");
			if (fscanf(stdin, "%d", & q) == 1)
				break;
		}
		r = p / q;
		fprintf(stdout, "rapport p / q = %d\n", r); 
	}
	return EXIT_SUCCESS;
}

