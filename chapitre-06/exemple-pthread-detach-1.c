// ------------------------------------------------------------------
// exemple-pthread-detach-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * fonction_thread(void * arg);

int main (int argc, char * argv[])
{
	pthread_t thr; /* La meme variable sera ecrasee a chaque fois */
	int nb_lances = 0;
	while (pthread_create(& thr, NULL, fonction_thread, NULL) == 0) {
		nb_lances ++;
		usleep(10000); /* 10 ms */
	}
	fprintf(stderr, "Echec de creation apres %d threads\n", nb_lances);
	return EXIT_SUCCESS;
}

void * fonction_thread(void * arg)
{
	return NULL;
}

