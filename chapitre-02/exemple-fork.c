// ------------------------------------------------------------------
// exemple-fork.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>

int main (void)
{
	pid_t child_pid;

	do {
		child_pid = fork();
	} while ((child_pid == -1) && (errno == EAGAIN));

	if (child_pid == -1) {
		fprintf(stderr, "unable to fork(), errno=%d\n", errno);
		return 1;
	}
	if (child_pid == 0) { /* child */
		fprintf(stdout, "Child:  PID=%ld, PPID=%ld\n",
		        (long)getpid(), (long)getppid());
		return 0;
	} else { /* parent */
		fprintf(stdout, "Parent: PID=%ld, PPID=%ld, child=%ld\n",
		        (long)getpid(),(long)getppid(),(long)child_pid);
		wait(NULL);
		return 0;
	}
}
