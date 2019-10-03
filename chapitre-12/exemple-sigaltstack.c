// ------------------------------------------------------------------
// exemple-sigaltstack.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void signal_handler(int num)
{
	stack_t stack;

	fprintf(stdout, "\nreceived %d\n", num);

	if (sigaltstack(NULL, &stack) != 0) {
		perror("sigaltstack()");
		return;
	}
	if (stack.ss_flags & SS_DISABLE)
		fprintf(stdout, "Alternate stack disabled\n");
	else
		fprintf(stdout, "Alternate stack enabled\n");

	if (stack.ss_flags & SS_ONSTACK)
		fprintf(stdout, "Alternate stack used\n");
	else
		fprintf(stdout, "Alternate unused\n");
}

int main (void)
{
	stack_t stack;
	struct sigaction action;
	
	if ((stack.ss_sp = malloc(SIGSTKSZ)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	stack.ss_size = SIGSTKSZ;
	stack.ss_flags = 0;

	if (sigaltstack(&stack, NULL) != 0) {
		perror("sigaltstack()");
		exit(EXIT_FAILURE);
	}

	action.sa_handler = signal_handler;
	sigemptyset(& (action.sa_mask));
	action.sa_flags = SA_RESTART | SA_ONSTACK;
	if (sigaction(SIGQUIT, &action, NULL) != 0) {
		perror("sigaction()");
		exit(EXIT_FAILURE);
	}

	action.sa_handler = signal_handler;
	sigemptyset(& (action.sa_mask));
	action.sa_flags = SA_RESTART;
	if (sigaction(SIGTERM, &action, NULL) != 0) {
		perror("sigaction()");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "PID = %ld\n", (long) getpid());
	fflush(stdout);

	while (1)
		pause();

	return EXIT_SUCCESS;
}

