// ------------------------------------------------------------------
// exemple-timer-create.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

	volatile int compteur = 0;

void gestionnaire_usr1(int numero)
{
	compteur ++;
}
void gestionnaire_usr2(int numero)
{
	fprintf(stderr, "%d\n", compteur);
	compteur = 0;
}

int main(int argc, char * argv[])
{
	long int        frequence;
	timer_t timer1, timer2;
	struct sigevent event;
	struct itimerspec itimer;

	if ((argc != 2)
	 || (sscanf(argv[1], "%ld", & frequence) != 1)
	 || (frequence < 2) || (frequence > 1000000000)) {
		fprintf(stderr, "usage: %s frequence\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	signal(SIGUSR1, gestionnaire_usr1);
	signal(SIGUSR2, gestionnaire_usr2);

	event.sigev_notify = SIGEV_SIGNAL;
	event.sigev_signo  = SIGUSR1;
	
	if (timer_create(CLOCK_REALTIME, & event, & timer1) != 0) {
		perror("timer_create");
		exit(EXIT_FAILURE);
	}

	event.sigev_notify = SIGEV_SIGNAL;
	event.sigev_signo  = SIGUSR2;

	if (timer_create(CLOCK_REALTIME, & event, & timer2) != 0) {
		perror("timer_create");
		exit(EXIT_FAILURE);
	}

	itimer.it_value.tv_sec = 0;
	itimer.it_value.tv_nsec = 1000000000/frequence;
	itimer.it_interval.tv_sec = 0;
	itimer.it_interval.tv_nsec = 1000000000/frequence;

	if (timer_settime(timer1, 0, & itimer, NULL) != 0) {
		perror("timer_settime");
		exit(EXIT_FAILURE);
	}

	itimer.it_value.tv_sec = 1;
	itimer.it_value.tv_nsec = 0;
	itimer.it_interval.tv_sec = 1;
	itimer.it_interval.tv_nsec = 0;

	if (timer_settime(timer2, 0, & itimer, NULL) != 0) {
		perror("timer_settime");
		exit(EXIT_FAILURE);
	}

	while (1)
		pause();
	return EXIT_SUCCESS;
}

