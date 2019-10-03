// ------------------------------------------------------------------
// exemple-sleep.c
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

void signal_handler(int num)
{ /* ne rien faire */
}

int main (void)
{
	pid_t            pid;
	time_t           t;
	unsigned int     sleep_time;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "Error during fork()\n");
		exit(EXIT_FAILURE);
	}
	/* installation d'un handler vide pour SIGUSR1 */
	signal(SIGUSR1, signal_handler);

	if (pid == 0) {
		/* enfant */
		time(&t);
		fprintf(stdout, "Before : %s", ctime(&t));
		sleep_time = sleep(10);
		time(&t);
		fprintf(stdout, "After  : %s", ctime(&t));
		fprintf(stdout, "Remaining sleep %u\n", sleep_time);
	} else {
		/* parent */
		sleep(2);
		/* envoi d'un signal vers le proicessus enfant */
		kill(pid, SIGUSR1);
		waitpid(pid, NULL, 0);
	}
	return EXIT_SUCCESS;
}
