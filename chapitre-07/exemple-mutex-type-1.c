// ------------------------------------------------------------------
// exemple-mutex-type-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void * fonction_thread(void * arg);

int main (void)
{
	pthread_t thr;
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

