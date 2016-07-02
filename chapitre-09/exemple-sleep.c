// ------------------------------------------------------------------
// exemple-sleep.c
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
	unsigned int     duree_sommeil;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "Erreur dans fork \n");
		exit(EXIT_FAILURE);
	}
	/* installation d'un handler vide pour SIGUSR1 */
	signal(SIGUSR1, gestionnaire_sigusr1);

	if (pid == 0) {
		/* fils */
		time(& heure);
		fprintf(stdout, "Avant : %s", ctime(& heure));
		duree_sommeil = sleep(10);
		time(& heure);
		fprintf(stdout, "Apres : %s", ctime(& heure));
		fprintf(stdout, "Duree restante %u\n", duree_sommeil);
	} else {
		/* pere */
		sleep(2);
		/* envoi d'un signal vers le fils */
		kill(pid, SIGUSR1);
		waitpid(pid, NULL, 0);
	}
	return EXIT_SUCCESS;
}
