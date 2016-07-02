// ------------------------------------------------------------------
// exemple-mutex-type-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int main (void)
{
	int ret;
	fprintf(stderr, "Je deverrouille le mutex...");
	ret = pthread_mutex_unlock(& mtx);
	fprintf(stderr, "retour %d\n", ret);
	pthread_exit(NULL);
}
