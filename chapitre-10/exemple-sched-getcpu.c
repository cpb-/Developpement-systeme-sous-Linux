// ------------------------------------------------------------------
// exemple-sched-getcpu.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * fonction (void * arg);

int main(int argc, char * argv[])
{
	long n;
	pthread_t thr;
	int nb_threads;

	if ((argc != 2)
	 || (sscanf(argv[1], "%d", & nb_threads) != 1)) {
		fprintf(stderr, "usage : %s nb_threads\n", argv[0]);
		exit(1);
	}
	for (n = 0; n < nb_threads; n ++)
		pthread_create(& thr, NULL, fonction, (void *) n);
	pthread_exit(NULL);
}

void * fonction (void * arg)
{
	long num = (long) arg;
	int precedent = -1;
	int cpu;
	while(1) {
		cpu = sched_getcpu();
		if (cpu != precedent) {
			fprintf(stdout, "[%ld] %d\n", num, cpu);
			precedent = cpu;
		}
	}
}

