// ------------------------------------------------------------------
// exemple-mutex-type-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _XOPEN_SOURCE 500 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mtx;

void * fonction_thread(void * arg);

int main (void)
{
	pthread_t thr;
	pthread_mutexattr_t attr; 
	pthread_mutexattr_init(& attr); 
	pthread_mutexattr_settype(& attr, PTHREAD_MUTEX_ERRORCHECK); 
	pthread_mutex_init(& mtx, & attr); 
	pthread_mutex_lock(& mtx);
	pthread_create(& thr, NULL, fonction_thread, NULL);
	pause();
	pthread_exit(NULL);
}

void * fonction_thread(void * arg)
{
	int ret;
	fprintf(stderr, "Thread deverrouille le mutex : ");
	ret = pthread_mutex_unlock(& mtx);
	fprintf(stderr, "resultat %d\n", ret);
	sleep(1);
	fprintf(stderr, "Thread re-verrouille le mutex : ");
	ret = pthread_mutex_lock(& mtx);
	fprintf(stderr, "resultat %d\n", ret);
	pthread_exit(NULL);
}

