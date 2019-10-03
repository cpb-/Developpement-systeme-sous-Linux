// ------------------------------------------------------------------
// exemple-sigqueue-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIGNAL_COUNT_MAX 10
int	received_signal[SIGNAL_COUNT_MAX];
int	received_value[SIGNAL_COUNT_MAX];
int	signal_count = 0;

void rt_signal_handler(int num, siginfo_t *info, void *unused)
{
	assert(signal_count < SIGNAL_COUNT_MAX);
	received_signal[signal_count] = num - SIGRTMIN;
	received_value[signal_count]  = info->si_value.sival_int;
	signal_count ++;
}

void rt_signal_send(int num, int value)
{
	union sigval sigvalue;

	fprintf(stdout, "Sending SIGRTMIN+%d, value %d\n",
	                  num, value);
	sigvalue.sival_int = value;
	if (sigqueue(getpid(), num + SIGRTMIN, sigvalue) < 0) {
		perror("sigqueue");
		exit(EXIT_FAILURE);
	}
}

int main (void)
{
	int i;
	sigset_t set;
	struct sigaction action;

	fprintf(stdout, "Installing handler\n");
	action.sa_sigaction = rt_signal_handler;
	sigfillset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGRTMIN + 1, &action, NULL) < 0)
	 || (sigaction(SIGRTMIN + 2, &action, NULL) < 0)
	 || (sigaction(SIGRTMIN + 3, &action, NULL) < 0)) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	
	fprintf(stdout, "Blocking all signals\n");
	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, NULL);

	rt_signal_send(1, 0);
	rt_signal_send(2, 1);
	rt_signal_send(3, 2);
	rt_signal_send(1, 3);
	rt_signal_send(2, 4);
	rt_signal_send(3, 5);
	rt_signal_send(3, 6);
	rt_signal_send(2, 7);
	rt_signal_send(1, 8);
	rt_signal_send(3, 9);
	
	fprintf(stdout, "Unblocking all signals\n");
	sigfillset(&set);
	sigprocmask(SIG_UNBLOCK, &set, NULL);

	fprintf(stdout, "Displaying result\n");
	for (i = 0; i < signal_count; i ++)
		fprintf(stdout, "Signal SIGRTMIN+%d, value %d\n",
                        received_signal[i], received_value[i]);
	return(EXIT_SUCCESS);
}

