// ------------------------------------------------------------------
// exemple-pthread-create-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_function(void *arg);

typedef struct {
	int X;
	int Y;
} coord_t;


int main (void)
{
	pthread_t thr;
	coord_t * coord;

	coord = malloc(sizeof(coord_t));
	if (coord == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	coord->X=10;
	coord->Y=20;
	if (pthread_create(& thr, NULL, thread_function, coord) != 0) {
		fprintf(stderr, "Error during pthread_create()\n");
		exit(EXIT_FAILURE);
	}
	while (1) {
		fprintf(stderr, "Main thread\n");
		sleep(1);
	}
}


void *thread_function(void *arg)
{
	coord_t *coord = (coord_t *) arg;

	int X = coord->X;
	int Y = coord->Y;

	free(coord);
	while (1) {
		fprintf(stderr, "Thread X=%d, Y=%d\n", X, Y);
		sleep(1);
	}
}

