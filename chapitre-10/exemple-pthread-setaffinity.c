// ------------------------------------------------------------------
// exemple-pthread-setaffinity.c
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
	int num_cpu;
	int nb_threads;
	pthread_t thr;
	cpu_set_t cpuset;

	if ((argc != 3)
	 || (sscanf(argv[1], "%d", & nb_threads) != 1)
	 || (sscanf(argv[2], "%d", & num_cpu) != 1)) {
		fprintf(stderr, "usage : %s nb_threads num_cpu\n", argv[0]);
		exit(1);
	}
	CPU_ZERO(& cpuset);
	CPU_SET(num_cpu, & cpuset);
	for (n = 0; n < nb_threads; n ++) {
		pthread_create(& thr, NULL, fonction, (void *) n);
		pthread_setaffinity_np(thr, sizeof(cpu_set_t), & cpuset);
	}
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

