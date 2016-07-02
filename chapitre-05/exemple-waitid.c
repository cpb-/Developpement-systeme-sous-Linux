// ------------------------------------------------------------------
// exemple-waitid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
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
		fprintf(stderr, "Erreur dans fork()\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		while (1) {
			fprintf(stderr, "[Fils %ld] : en fonctionnement\n", (long int) getpid());
			sleep(3);
			fprintf(stderr, "Fils %ld va se stopper\n", (long int) getpid());
			raise(SIGSTOP);
		}
	}
	while (1) {
		fprintf(stderr, "   [Pere] : en attente\n");
		if (waitid(P_ALL, 0, & info, WSTOPPED) == 0) {
			if (info.si_code == CLD_STOPPED) {
				fprintf(stdout, "   [Pere] : mon fils %ld arrete par signal %d\n",
						(long)pid, info.si_status);
				sleep(2);
				fprintf(stdout, "   [Pere] Je le relance\n");
				kill(info.si_pid, SIGCONT);
			}
		} else if (errno == ECHILD) {
			/* Plus de fils */
			break;
		}
	}
	return EXIT_SUCCESS;
}
