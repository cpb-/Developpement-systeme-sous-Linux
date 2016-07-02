// ------------------------------------------------------------------
// exemple-mutex-type-2.c
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
	fprintf(stderr, "Je verrouille le mutex...");
	if (pthread_mutex_lock(& mtx) == 0)
		fprintf(stderr, "Ok\n");
	else
		fprintf(stderr, "Erreur\n");
	sleep(1);
	fprintf(stderr, "Je verrouille a nouveau le mutex...");
	if (pthread_mutex_lock(& mtx) == 0)
		fprintf(stderr, "Ok\n");
	else
		fprintf(stderr, "Erreur\n");
	pthread_exit(NULL);
}
