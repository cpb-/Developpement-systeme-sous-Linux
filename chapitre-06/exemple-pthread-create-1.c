// ------------------------------------------------------------------
// exemple-pthread-create-1.c
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
	pthread_t thr;
	if (pthread_create(& thr, NULL, fonction_thread, NULL) != 0) {
		fprintf(stderr, "Erreur dans pthread_create\n");
		exit(EXIT_FAILURE);
	}
	while (1) {
		fprintf(stderr, "Thread Main\n");
		sleep(1);
	}
}

void * fonction_thread(void * arg)
{
	while (1) {
		fprintf(stderr, "Nouveau Thread\n");
		sleep(1);
	}
}

