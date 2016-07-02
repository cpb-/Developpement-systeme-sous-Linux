// ------------------------------------------------------------------
// exemple-usleep-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

void gestionnaire_sigusr1(int numero)
{ /* ne rien faire */
}

int main (void)
{
	pid_t            pid;
	time_t           heure;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "Erreur dans fork \n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, gestionnaire_sigusr1);

	if (pid == 0) {
		time(& heure);
		fprintf(stdout, "Avant : %s", ctime(& heure));
		usleep(10000000); /* 10 millions de us = 10 secondes */
		time(& heure);
		fprintf(stdout, "Apres : %s", ctime(& heure));
	} else {
		usleep(2000000); /* 2 millions de us = 2 secondes */
		kill(pid, SIGUSR1);
		waitpid(pid, NULL, 0);
	}
	return EXIT_SUCCESS;
}
