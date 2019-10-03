// ------------------------------------------------------------------
// exemple-mutex-type-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _XOPEN_SOURCE 500 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mtx;

void * thread_function(void * arg);

int main (void)
{
	pthread_t thr;
	pthread_mutexattr_t attr; 

	pthread_mutexattr_init(&attr); 
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK); 
	pthread_mutex_init(&mtx, &attr); 
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
	fprintf(stderr, "pthread_mutex_lock() : ");
	fprintf(stderr, "%d\n",
		pthread_mutex_lock(&mtx));
	pthread_exit(NULL);
}
