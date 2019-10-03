// ------------------------------------------------------------------
// exemple-wait-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


void display_status(pid_t pid, int status);
int  child_process(int number);

int main (void)
{
	pid_t pid;
	int   status;
	int   child;

	for (child = 0; child < 4; child ++) {

		switch (fork()) {
			case -1 :
				fprintf(stderr, "Erreur during fork()\n");
				exit(EXIT_FAILURE);
			case 0 :
				fprintf(stdout, "Child %d : PID = %ld\n",
					child, (long)getpid());
				return child_process(child);
			default :
				/* parent */
				break;
		}
	}

	/* Ici il n'y a plus que le processus parent */
	while ((pid = wait(&status)) > 0)
		display_status(pid, status);

	return EXIT_SUCCESS;
}


void display_status (pid_t pid, int status)
{
	fprintf(stdout, "The process %ld ", (long)pid);
	if (WIFEXITED(status)) {
		fprintf (stdout, "terminates normaly with code %d\n",
				 WEXITSTATUS(status));
	} else if (WIFSIGNALED(status)) {
		fprintf (stdout, "was killed by signal %d (%s)\n",
				WTERMSIG(status),
				sys_siglist[WTERMSIG(status)]);
		if (WCOREDUMP(status)) {
			fprintf(stdout, "Core file created\n");
		}
	} else if (WIFSTOPPED(status)) {
		fprintf(stdout, "was stopped by signal %d (%s)\n",
				WSTOPSIG(status),
				sys_siglist[WSTOPSIG(status)]);
	}
}

int child_process(int number)
{
	switch (number) {

		case 0 :
			return 1;
		case 1 :
			exit(2);
		case 2 :
			abort();
		case 3 :
			raise(SIGUSR1);
	}
	return number;
}

