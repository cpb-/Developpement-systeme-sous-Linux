// ------------------------------------------------------------------
// exemple-fork.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>

int main (void)
{
	pid_t pid_fils;

	do {
		pid_fils = fork();
	} while ((pid_fils == -1) && (errno == EAGAIN));

	if (pid_fils == -1) {
		fprintf(stderr, "fork() impossible, errno=%d\n", errno);
		return 1;
	}
	if (pid_fils == 0) { /* processus fils */
		fprintf(stdout, "Fils : PID=%ld, PPID=%ld\n",
		        (long)getpid(), (long)getppid());
		return 0;
	} else { /* processus pere */
		fprintf(stdout, "Pere : PID=%ld, PPID=%ld, PID fils=%ld\n",
		        (long)getpid(),(long)getppid(),(long)pid_fils);
		wait(NULL);
		return 0;
	}
}
