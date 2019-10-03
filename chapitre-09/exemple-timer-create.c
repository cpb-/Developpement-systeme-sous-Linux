// ------------------------------------------------------------------
// exemple-timer-create.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

	volatile int counter = 0;

void usr1_handler(int num)
{
	counter++;
}


void usr2_handler(int num)
{
	fprintf(stderr, "%d\n", counter);
	counter = 0;
}

int main(int argc, char * argv[])
{
	long int        frequency;
	timer_t timer1, timer2;
	struct sigevent event;
	struct itimerspec itimer;

	if ((argc != 2)
	 || (sscanf(argv[1], "%ld", &frequency) != 1)
	 || (frequency < 2) || (frequency > 1000000000)) {
		fprintf(stderr, "usage: %s frequency\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	signal(SIGUSR1, usr1_handler);
	signal(SIGUSR2, usr2_handler);

	event.sigev_notify = SIGEV_SIGNAL;
	event.sigev_signo  = SIGUSR1;
	
	if (timer_create(CLOCK_REALTIME, &event, &timer1) != 0) {
		perror("timer_create");
		exit(EXIT_FAILURE);
	}

	event.sigev_notify = SIGEV_SIGNAL;
	event.sigev_signo  = SIGUSR2;

	if (timer_create(CLOCK_REALTIME, &event, &timer2) != 0) {
		perror("timer_create");
		exit(EXIT_FAILURE);
	}

	itimer.it_value.tv_sec = 0;
	itimer.it_value.tv_nsec = 1000000000/frequency;
	itimer.it_interval.tv_sec = 0;
	itimer.it_interval.tv_nsec = 1000000000/frequency;

	if (timer_settime(timer1, 0, &itimer, NULL) != 0) {
		perror("timer_settime");
		exit(EXIT_FAILURE);
	}

	itimer.it_value.tv_sec = 1;
	itimer.it_value.tv_nsec = 0;
	itimer.it_interval.tv_sec = 1;
	itimer.it_interval.tv_nsec = 0;

	if (timer_settime(timer2, 0, &itimer, NULL) != 0) {
		perror("timer_settime");
		exit(EXIT_FAILURE);
	}

	while (1)
		pause();
	return EXIT_SUCCESS;
}

