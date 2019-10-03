// ------------------------------------------------------------------
// exemple-status.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void display_status(pid_t pid)
{
	FILE * fp;
	char   string[80];

	sprintf(string, "/proc/%ld/status", (long) pid);
	if ((fp = fopen(string, "r")) == NULL) {
		fprintf(stdout, "absent\n");
		return;
	}
	while (fgets(string, 80, fp) != NULL)
		if (strncmp(string, "State", 5) == 0) {
			fputs(string, stdout);
			break;
		}
	fclose(fp);
}

int main (void)
{
	pid_t pid;
	char  string[5];

	fprintf(stdout, "PID = %ld\n", (long) getpid());
	fprintf(stdout, "Expected state = Running \n");
	display_status(getpid());

	if ((pid = fork()) == -1) {
		perror("fork ()");
		exit(EXIT_FAILURE);
	}
	if (pid != 0) {
		sleep(5);
		fprintf(stdout, "Parent: reading my child state...\n");
		fprintf(stdout, "Expected state = Zombie \n");
		display_status(pid);
		fprintf(stdout, "Parent: reading my child exit code...\n");
		wait(NULL);
		fprintf(stdout, "State of my child...\n");
		fprintf(stdout, "Expected state = absent\n");
		display_status(pid);
	} else {
		fprintf(stdout, "Child: reading my parent state...\n");
		fprintf(stdout, "Expected state = Sleeping \n");
		display_status(getppid());	
		fprintf(stdout, "Child: exit() \n");
		exit(EXIT_SUCCESS);
	}
	fprintf(stdout, "Waiting for input\n");
	fgets(string, 5, stdin);
	exit(EXIT_SUCCESS);
}


