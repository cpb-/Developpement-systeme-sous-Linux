// ------------------------------------------------------------------
// exemple-usleep-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

void signal_handler(int numero)
{ /* ne rien faire */
}

int main (void)
{
	pid_t            pid;
	time_t           t;

	if ((pid = fork()) < 0) {
		perror("fork ()");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, signal_handler);

	if (pid == 0) {
		time(&t);
		fprintf(stdout, "Before : %s", ctime(&t));
		usleep(10000000); /* 10 millions de us = 10 secondes */
		time(&t);
		fprintf(stdout, "After  : %s", ctime(&t));
	} else {
		usleep(2000000); /* 2 millions de us = 2 secondes */
		kill(pid, SIGUSR1);
		waitpid(pid, NULL, 0);
	}
	return EXIT_SUCCESS;
}
