// ------------------------------------------------------------------
// exemple-pthread-cancel-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * thread_function(void * arg);

int main (void)
{
	pthread_t thr1, thr2;

	if ((pthread_create(&thr1, NULL, thread_function, (void *) 1) != 0)
	 || (pthread_create(&thr2, NULL, thread_function, (void *) 2) != 0)) {
		fprintf(stderr, "Error during pthread_create\n");
		exit(EXIT_FAILURE);
	}
	sleep(3);
	fprintf(stderr, "[main] Calling pthread_cancel()...\n");
	pthread_cancel(thr1);
	pthread_cancel(thr2);
	pthread_exit(NULL);
}


void * thread_function(void * arg)
{
	long num = (long) arg;

	if (num == 1)
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	while (1) {
		fprintf(stderr, "[Thread %ld] Running...\n", num);
		sleep(1);
	}
}
