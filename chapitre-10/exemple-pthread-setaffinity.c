// ------------------------------------------------------------------
// exemple-pthread-setaffinity.c
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
	int cpu;
	int nb_threads;
	pthread_t thr;
	cpu_set_t cpuset;

	if ((argc != 3)
	 || (sscanf(argv[1], "%d", &nb_threads) != 1)
	 || (sscanf(argv[2], "%d", &cpu) != 1)) {
		fprintf(stderr, "usage : %s nb_threads cpu\n", argv[0]);
		exit(1);
	}
	CPU_ZERO(&cpuset);
	CPU_SET(cpu, &cpuset);
	for (n = 0; n < nb_threads; n ++) {
		pthread_create(&thr, NULL, thread_function, (void *) n);
		pthread_setaffinity_np(thr, sizeof(cpu_set_t), &cpuset);
	}
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

