// ------------------------------------------------------------------
// exemple-alarm.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>

sigjmp_buf	sigalrm_context;

void signal_handler(int inutilise)
{
	siglongjmp(sigalrm_context, 1);
}

int main (void)
{
	char	line[80];
	int	i;
	struct sigaction action;

	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	sigfillset(& action.sa_mask);
	sigaction(SIGALRM, & action, NULL);

	fprintf(stdout, "Entrez un nombre entier avant 5 secondes : ");

	if (sigsetjmp(sigalrm_context, 1) == 0) {
		/* premier passage, installation */
		alarm(5);
	
		/* Lecture et analyse de la ligne saisie */
		while (1) {
			if (fgets(line, 79, stdin) != NULL)
				if (sscanf(line, "%d", & i) == 1)
					break;
			fprintf(stdout, "Un entier svp : ");
		}

		/* Ok - La ligne est bonne */
		alarm(0);
		fprintf(stdout, "Ok !\n");

	} else {
		/* On est arrive par SIGALRM */
		fprintf(stdout, "\nTrop tard !\n");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

