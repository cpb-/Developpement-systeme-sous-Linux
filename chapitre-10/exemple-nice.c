// ------------------------------------------------------------------
// exemple-nice.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

volatile long counter = 0;
static int    nice_value;

void signal_handler(int numero)
{
	if (counter != 0) {
		fprintf(stdout, "Child %ld (nice %2d) Counter = %10ld\n",
		                 (long) getpid(), nice_value, counter);
		exit(EXIT_SUCCESS);
	}
}

#define NB_CHILD    5

int main (void)
{
	pid_t   pid;
	int     child;

	/* Creation d'un nouveau groupe de processus */
	setpgid(0, 0);

	signal(SIGUSR1, signal_handler);
	for (child = 0; child < NB_CHILD; child ++) {
		if ((pid = fork()) < 0) {
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid != 0)
			continue;
		nice_value = child * (20 / (NB_CHILD - 1));
		if (nice(nice_value) < 0) {
			perror("nice");
			exit(EXIT_FAILURE);
		}
		/* attente signal de demarrage */
		pause();
		/* comptage */
		while (1)
			counter ++;
	}
	/* processus parent */
	signal(SIGUSR1, SIG_IGN);
	sleep(1);
	kill(-getpgid(0), SIGUSR1);
	sleep(5);
	kill(-getpgid(0), SIGUSR1);
	while (wait(NULL) > 0)
		;
	exit(EXIT_SUCCESS);
}

