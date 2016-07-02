// ------------------------------------------------------------------
// exemple-wait-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int main (void)
{
	pid_t	pid;
	int	status;

	switch (pid = fork()) {
		case -1 :
			fprintf(stderr, "Erreur dans fork()\n");
			exit(EXIT_FAILURE);
		case 0 : /* fils 1 */
			fprintf(stdout, "Fils 1 : PID = %ld\n", (long)getpid());
			while (1)
				pause();
		default : /* pere */
			break;
	}

	/* Creons un fils que l'on n'attend pas */
	switch (fork()) {
		case -1 :
			fprintf(stderr, "Erreur dans fork()\n");
			exit(EXIT_FAILURE);
		case 0 : /* fils 2 */
			fprintf(stdout, "Fils 2 : PID = %ld\n", (long)getpid());
			sleep(2);	
			exit(EXIT_FAILURE);
		default : /* pere */
			break;
	}
	while (1) {
		sleep(1);
		if (waitpid(pid, & status, WUNTRACED | WNOHANG) > 0) {
			if (WIFEXITED(status)) {
				fprintf(stdout, "%ld termine par exit (%d)\n",
						(long)pid, WEXITSTATUS(status));
				exit(EXIT_SUCCESS);
			} else if (WIFSIGNALED(status)) {
				fprintf(stdout, "%ld termine par signal %d\n",
						(long)pid, WTERMSIG(status));
				exit(EXIT_SUCCESS);
			} else if (WIFSTOPPED(status)) {
				fprintf(stdout, "%ld stoppe par signal %d\n",
						(long)pid, WSTOPSIG(status));
			}
		} 
	}
	return EXIT_SUCCESS;
}

