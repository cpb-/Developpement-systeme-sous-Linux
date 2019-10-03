// ------------------------------------------------------------------
// exemple-siginterrupt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void signal_handler(int num)
{
	fprintf(stdout, "\n received signal: %d\n", num); 
}

int main (int argc, char *argv[])
{
	int flag;

	if ((argc != 2) || (sscanf(argv[1], "%d", &flag) != 1)) {
		fprintf (stderr, "Syntaxe : %s {0|1}\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	signal(SIGTSTP, signal_handler);
	siginterrupt(SIGTSTP, flag);

	while (1) {
		fprintf(stdout, "calling read()\n");
		if (read(STDIN_FILENO, &flag, sizeof(int)) < 0)
			if (errno == EINTR)
				fprintf(stdout, "EINTR \n");
	}
	return EXIT_SUCCESS;
}
