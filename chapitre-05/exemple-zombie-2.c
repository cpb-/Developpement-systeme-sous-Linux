// ------------------------------------------------------------------
// exemple-zombie-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int   i;
	pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "error during fork()\n");
		exit(EXIT_FAILURE);
	}

	if (pid != 0) {
		fprintf(stdout, "Parent : my PID is %ld\n", (long)getpid());
		sleep(2);
		fprintf(stdout, "Parent : terminating\n");
		exit(EXIT_SUCCESS);

	} else {
		for (i = 0; i < 5; i ++) {
			fprintf(stdout, "Child : my parent is %ld\n", (long)getppid());
			sleep(1);
		}
	}
	return EXIT_SUCCESS;
}
