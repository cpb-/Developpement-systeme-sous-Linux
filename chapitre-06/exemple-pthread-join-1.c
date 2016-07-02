// ------------------------------------------------------------------
// exemple-pthread-join-1.c
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
	pthread_t * thr = NULL;
	void * ptr;
	int i;
	long n;
	thr = calloc(argc - 1, sizeof(pthread_t));
	if (thr == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < argc; i ++) {
		n = atol(argv[i]);
		if (pthread_create(& thr[i-1], NULL, fonction_thread, (void *) n) != 0) {
			fprintf(stderr, "Erreur dans pthread_create\n");
			exit(EXIT_FAILURE);
		}
	}
	for (i = 1; i < argc; i ++) {
		pthread_join(thr[i - 1], & ptr);
		fprintf(stderr, "%d -> %ld\n", atoi(argv[i]), (long) ptr);
	}
	return EXIT_SUCCESS;
}

void * fonction_thread(void * arg)
{
	long num = (long) arg;
	return (void *) (num * num);
}

