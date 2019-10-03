// ------------------------------------------------------------------
// exemple-perror.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main (void)
{
	struct rlimit limit;
	pid_t	pid;

	if (getrlimit(RLIMIT_NPROC, &limit) != 0) {
		perror("getrlimit");
		exit(EXIT_FAILURE);
	}
	limit.rlim_cur = 16;
	if (setrlimit(RLIMIT_NPROC, &limit) != 0) {
		perror("setrlimit");
		exit(EXIT_FAILURE);
	}
	while (1) {
		pid = fork();
		if (pid == (pid_t) -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid != 0) {
			fprintf(stdout, "%d\n", pid);
			if (waitpid(pid, NULL, 0) != pid)
				perror("waitpid");
			break;
		}
	}
	return EXIT_SUCCESS;
}
