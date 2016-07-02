// ------------------------------------------------------------------
// exemple-pthread-create-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * fonction_thread(void * arg);

#define NB_THREADS 5

int main (void)
{
	pthread_t thr[NB_THREADS];
	long n;
	for (n = 0; n < NB_THREADS; n ++) {
		if (pthread_create(& thr[n], NULL, fonction_thread, (void *) n) != 0) {
			fprintf(stderr, "Erreur dans pthread_create\n");
			exit(EXIT_FAILURE);
		}
	}
	while (1) {
		fprintf(stderr, "Thread Main\n");
		sleep(1);
	}
}

void * fonction_thread(void * arg)
{
	long num = (long) arg;
	while (1) {
		fprintf(stderr, "Thread numero %ld\n", num+1);
		sleep(1);
	}
}

