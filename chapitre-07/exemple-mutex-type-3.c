// ------------------------------------------------------------------
// exemple-mutex-type-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int main (void)
{
	fprintf(stderr, "pthread_mutex_unlock(): %d\n",
		pthread_mutex_unlock(&mtx));

	pthread_exit(NULL);
}
