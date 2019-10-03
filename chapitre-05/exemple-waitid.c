// ------------------------------------------------------------------
// exemple-waitid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/resource.h>

int main (void)
{
	pid_t	pid;
	siginfo_t info;

	pid = fork();
	if (pid == -1) {
		fprintf(stderr, "Error in fork()\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		while (1) {
			fprintf(stderr, "[child %ld] : running\n", (long int) getpid());
			sleep(3);
			fprintf(stderr, "child %ld will stop\n", (long int) getpid());
			raise(SIGSTOP);
		}
	}
	while (1) {
		fprintf(stderr, "   [parent] : waiting\n");
		if (waitid(P_ALL, 0, &info, WSTOPPED) == 0) {
			if (info.si_code == CLD_STOPPED) {
				fprintf(stdout, "   [parent] : my child %ld was stopped by signal %d\n",
						(long)pid, info.si_status);
				sleep(2);
				fprintf(stdout, "   [parent] restarting him\n");
				kill(info.si_pid, SIGCONT);
			}
		} else if (errno == ECHILD) {
			/* No more child */
			break;
		}
	}
	return EXIT_SUCCESS;
}
