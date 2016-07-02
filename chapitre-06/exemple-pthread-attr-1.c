// ------------------------------------------------------------------
// exemple-pthread-attr-1.c
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
	pthread_t thr;
	pthread_attr_t attr;
	int nb_lances = 0;
	pthread_attr_init(& attr);
	pthread_attr_setdetachstate(& attr, PTHREAD_CREATE_DETACHED);
	while (pthread_create(& thr, & attr, fonction_thread, NULL) == 0) {
		nb_lances ++;
		if ((nb_lances % 100) == 0)
			fprintf(stderr, "%d thread lances\n", nb_lances);
		usleep(10000);
	}
	pthread_attr_destroy(& attr);
	fprintf(stderr, "Echec de creation apres %d threads\n", nb_lances);
	return EXIT_SUCCESS;
}

void * fonction_thread(void * arg)
{
	return NULL;
}

