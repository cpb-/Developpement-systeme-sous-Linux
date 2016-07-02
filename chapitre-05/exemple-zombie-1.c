// ------------------------------------------------------------------
// exemple-zombie-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	pid_t pid;
	char  commande[128];

	if ((pid = fork()) < 0) {
		fprintf(stderr, "echec fork()\n");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		/* processus fils */
		sleep(2);
		fprintf(stdout, "Le processus fils %ld se termine\n", (long) getpid());
		exit(EXIT_SUCCESS);

	} else {
		/* processus pere */
		snprintf(commande, 128, "ps %ld", (long)pid);
		system(commande);
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
		sleep(1);
		system(commande);
	}
	return EXIT_SUCCESS;
}	
