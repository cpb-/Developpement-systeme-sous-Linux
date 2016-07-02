// ------------------------------------------------------------------
// exemple-wait-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


void affichage_type_de_terminaison (pid_t pid, int status);
int	 processus_fils                (int numero);

int main (void)
{
	pid_t	pid;
	int	status;
	int	numero_fils;

	for (numero_fils = 0; numero_fils < 4; numero_fils ++) {

		switch (fork()) {
			case -1 :
				fprintf(stderr, "Erreur dans fork()\n");
				exit(EXIT_FAILURE);
			case 0 :
				fprintf(stdout, "Fils %d : PID = %ld\n",
					numero_fils, (long)getpid());
				return processus_fils(numero_fils);
			default :
				/* processus pere */
				break;
		}
	}

	/* Ici il n'y a plus que le processus pere */

	while ((pid = wait(& status)) > 0)
		affichage_type_de_terminaison(pid, status);

	return EXIT_SUCCESS;
}

void affichage_type_de_terminaison (pid_t pid, int status)
{
	fprintf(stdout, "Le processus %ld ", (long)pid);
	if (WIFEXITED(status)) {
		fprintf (stdout, "s'est termine normalement avec le code %d\n",
				 WEXITSTATUS(status));
	} else if (WIFSIGNALED(status)) {
		fprintf (stdout, "s'est termine a cause du signal %d (%s)\n",
				WTERMSIG(status),
				sys_siglist[WTERMSIG(status)]);
		if (WCOREDUMP(status)) {
			fprintf(stdout, "Fichier image core cree\n");
		}
	} else if (WIFSTOPPED(status)) {
		fprintf(stdout, "s'est arrete a cause du signal %d (%s)\n",
				WSTOPSIG(status),
				sys_siglist[WSTOPSIG(status)]);
	}
}

int processus_fils (int numero)
{
	switch (numero) {

		case 0 :
			return 1;
		case 1 :
			exit(2);
		case 2 :
			abort();
		case 3 :
			raise(SIGUSR1);
	}
	return numero;
}
