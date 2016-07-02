// ------------------------------------------------------------------
// exemple-pthread-exit-2.c
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
	pthread_t thr[3];
	long n;

	for (n = 0; n < 3; n ++) {
		if (pthread_create(&thr[n], NULL, fonction_thread, (void *)n) != 0) {
			fprintf(stderr, "Erreur dans pthread_create\n");
			exit(EXIT_FAILURE);
		}
	}
	pthread_exit(NULL);
}

void * fonction_thread(void * arg)
{
	long num = (long) arg;
	while (1) {
		fprintf(stderr, "Thread %ld\n", num);
		sleep(1);
	}
}

