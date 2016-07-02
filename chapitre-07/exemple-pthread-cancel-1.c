// ------------------------------------------------------------------
// exemple-pthread-cancel-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * fonction_thread(void * arg);

int main (void)
{
	pthread_t thr1, thr2;
	if ((pthread_create(& thr1, NULL, fonction_thread, (void *) 1) != 0)
	 || (pthread_create(& thr2, NULL, fonction_thread, (void *) 2) != 0)) {
		fprintf(stderr, "Erreur dans pthread_create\n");
		exit(EXIT_FAILURE);
	}
	sleep(3);
	fprintf(stderr, "[main] envoi des annulations\n");
	pthread_cancel(thr1);
	pthread_cancel(thr2);
	pthread_exit(NULL);
}

void * fonction_thread(void * arg)
{
	long num = (long) arg;
	if (num == 1)
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	while (1) {
		fprintf(stderr, "[Thread %ld] Je suis la\n", num);
		sleep(1);
	}
}

