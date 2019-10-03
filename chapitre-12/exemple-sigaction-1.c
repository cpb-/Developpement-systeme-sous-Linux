// ------------------------------------------------------------------
// exemple-sigaction-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void signal_handler(int num)
{
	switch (num) {
		case SIGQUIT :
			fprintf(stdout, "\nreceived SIGQUIT\n");
			break;
		case SIGINT :
			fprintf(stdout, "\nreceived SIGINT\n");
			break;
	}
}

int main (void)
{
	struct sigaction action;

	action.sa_handler = signal_handler;
	sigemptyset(& (action.sa_mask));
	action.sa_flags = 0;

	if (sigaction(SIGQUIT, &action, NULL) != 0) {
		perror("sigaction(SIGQUIT)");
		exit(EXIT_FAILURE);
	}

	action.sa_flags = SA_RESTART | SA_RESETHAND;

	if (sigaction(SIGINT, & action, NULL) != 0) {
		perror("sigaction(SIGINT)");
		exit(EXIT_FAILURE);
	}

	/* Lecture continue, pour avoir un appel-systeme bloque */
	while (1) {
		int i;
		fprintf(stdout, "calling read()\n");
		if (read(0, & i, sizeof(int)) < 0)
			if (errno == EINTR)
				fprintf(stdout, "EINTR \n");
	}
	return EXIT_SUCCESS;

}

