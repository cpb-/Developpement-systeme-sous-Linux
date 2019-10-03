// ------------------------------------------------------------------
// exemple-sched-getcpu.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * thread_function(void * arg);

int main(int argc, char * argv[])
{
	long n;
	pthread_t thr;
	int nb_threads;

	if ((argc != 2)
	 || (sscanf(argv[1], "%d", &nb_threads) != 1)) {
		fprintf(stderr, "usage : %s nb_threads\n", argv[0]);
		exit(1);
	}
	for (n = 0; n < nb_threads; n ++)
		pthread_create(&thr, NULL, thread_function, (void *) n);
	pthread_exit(NULL);
}

void * thread_function(void * arg)
{
	long num = (long) arg;
	int previous = -1;
	int cpu;

	while(1) {
		cpu = sched_getcpu();
		if (cpu != previous) {
			fprintf(stdout, "[%ld] %d\n", num, cpu);
			previous = cpu;
		}
	}
}

