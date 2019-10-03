// ------------------------------------------------------------------
// exemple-wait-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int main (void)
{
	pid_t pid;
	int   status;

	switch (pid = fork()) {
		case -1 :
			fprintf(stderr, "Error during fork()\n");
			exit(EXIT_FAILURE);
		case 0 :
			fprintf(stdout, "Child 1: PID = %ld\n", (long)getpid());
			while (1)
				pause();
		default : /* parent */
			break;
	}

	/* Creons un enfant dont on n'attend pas la fin */
	switch (fork()) {
		case -1 :
			fprintf(stderr, "Error during fork()\n");
			exit(EXIT_FAILURE);
		case 0 :
			fprintf(stdout, "Child 2: PID = %ld\n", (long)getpid());
			sleep(2);
			exit(EXIT_FAILURE);
		default :
			break;
	}
	while (1) {
		sleep(1);
		if (waitpid(pid, &status, WUNTRACED | WNOHANG) > 0) {
			if (WIFEXITED(status)) {
				fprintf(stdout, "%ld terminates with exit(%d)\n",
						(long)pid, WEXITSTATUS(status));
				exit(EXIT_SUCCESS);
			} else if (WIFSIGNALED(status)) {
				fprintf(stdout, "%ld killed by signal %d\n",
						(long)pid, WTERMSIG(status));
				exit(EXIT_SUCCESS);
			} else if (WIFSTOPPED(status)) {
				fprintf(stdout, "%ld stopped by signal %d\n",
						(long)pid, WSTOPSIG(status));
			}
		}
	}
	return EXIT_SUCCESS;
}

