// ------------------------------------------------------------------
// exemple-signal-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------
#define	_XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int num)
{
	int i;

	signal(num, signal_handler);
	fprintf(stdout, "start of signal handler %d\n", num);
	for (i = 1; i < 4; i ++) {
		fprintf(stdout, "%d\n", i);
		sleep(1);
	}
	fprintf(stdout, "end of signal handler %d\n", num);
}

int main (void)
{
	signal(SIGUSR1, signal_handler);
	
	if (fork() == 0) {
		kill(getppid(), SIGUSR1);
		sleep(1);
		kill(getppid(), SIGUSR1);
	} else {
		while (1)
			pause();
	}
	return EXIT_SUCCESS;
}

