// ------------------------------------------------------------------
// exemple-zombie-1.c
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
	char  command[128];

	if ((pid = fork()) < 0) {
		fprintf(stderr, "error during fork()\n");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		/* child process */
		sleep(2);
		fprintf(stdout, "Child process %ld terminates\n", (long) getpid());
		exit(EXIT_SUCCESS);

	} else {
		/* parent process */
		snprintf(command, 128, "ps %ld", (long)pid);
		for (i = 0; i < 5; i ++) {
			system(command);
			sleep(1);
		}
	}
	return EXIT_SUCCESS;
}


