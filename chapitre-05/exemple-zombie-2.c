// ------------------------------------------------------------------
// exemple-zombie-2.c
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

	
	if ((pid = fork()) < 0) {
		fprintf(stderr, "echec fork()\n");
		exit(EXIT_FAILURE);
	}


	if (pid != 0) {
		/* processus père */
		fprintf(stdout, "Pere : mon PID est %ld\n", (long)getpid());
		sleep(2);
		fprintf(stdout, "Pere : je me termine\n");
		exit(EXIT_SUCCESS);

	} else {
		/* processus fils */
		fprintf(stdout, "Fils : mon pere est %ld\n", (long)getppid());
		sleep(1);
		fprintf(stdout, "Fils : mon pere est %ld\n", (long)getppid());
		sleep(1);
		fprintf(stdout, "Fils : mon pere est %ld\n", (long)getppid());
		sleep(1);
		fprintf(stdout, "Fils : mon pere est %ld\n", (long)getppid());
		sleep(1);
		fprintf(stdout, "Fils : mon pere est %ld\n", (long)getppid());
	}
	return EXIT_SUCCESS;
}	
