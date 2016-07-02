// ------------------------------------------------------------------
// exemple-siglongjmp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

sigjmp_buf	contexte;

void gestionnaire_sigfpe (int numero)
{
	siglongjmp(contexte, 1);
	/* Si l'on est ici le saut a rate, il faut quitter */
	signal(numero, SIG_DFL);
	raise(numero);
}

int main (void)
{
	int p, q, r;

	struct sigaction action;

	action.sa_handler = gestionnaire_sigfpe;
	action.sa_flags = 0;
	sigfillset(& action.sa_mask);
	sigaction(SIGFPE, & action, NULL);

	while (1) {
		if (sigsetjmp(contexte, 1) != 0) {
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

