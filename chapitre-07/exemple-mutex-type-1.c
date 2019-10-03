// ------------------------------------------------------------------
// exemple-mutex-type-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void * thread_function(void * arg);

int main (void)
{
	pthread_t thr;

	pthread_mutex_lock(&mtx);
	pthread_create(&thr, NULL, thread_function, NULL);
	pause();

	pthread_exit(NULL);
}


void * thread_function(void * arg)
{
	sleep(1);
	fprintf(stderr, "pthread_mutex_unlock() : %d\n",
		pthread_mutex_unlock(&mtx));
	sleep(1);
	fprintf(stderr, "pthread_mutex_lock() : %d\n",
		pthread_mutex_lock(&mtx));
	pthread_exit(NULL);
}
