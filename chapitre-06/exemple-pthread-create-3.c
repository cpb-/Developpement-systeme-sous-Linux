// ------------------------------------------------------------------
// exemple-pthread-create-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * fonction_thread(void * arg);


typedef struct {
	int X;
	int Y;
} coordonnee_t;

int main (void)
{
	pthread_t thr;
	coordonnee_t * coord;

	coord = malloc(sizeof(coordonnee_t));
	if (coord == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	coord->X=10;
	coord->Y=20;
	if (pthread_create(& thr, NULL, fonction_thread, coord) != 0) {
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
	coordonnee_t * coord = (coordonnee_t *) arg;
	int X = coord->X;
	int Y = coord->Y;
	free(coord);
	while (1) {
		fprintf(stderr, "Thread X=%d, Y=%d\n", X, Y);
		sleep(1);
	}
}

