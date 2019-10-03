// ------------------------------------------------------------------
// exemple-pthread-mutex-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static void * thread_function(void *arg);
static int    random_value(int maximum);

pthread_mutex_t	mutex_stdout = PTHREAD_MUTEX_INITIALIZER;

int main (void)
{
	long       i;
	pthread_t  thread;

	for (i = 0; i < 5; i ++)
		pthread_create(& thread, NULL, thread_function, (void *) i);
	pthread_exit(NULL);
}


static void *thread_function (void * argument)
{
	long num = (long) argument;
	int loops;
	int i;

	loops = 1 + random_value(3);

	for (i = 0; i < loops; i ++) {
		sleep(random_value(3));
		pthread_mutex_lock(&mutex_stdout);
		fprintf(stdout, "Thread #%ld hold the mutex\n", num);
		sleep(random_value(3));
		fprintf(stdout, "Thread #%ld release the mutex\n", num);
		pthread_mutex_unlock(&mutex_stdout);
	}
	return NULL;
}


static int random_value (int maximum)
{
	double d;

	d = (double) maximum * rand();
	d = d / (RAND_MAX + 1.0);
	return ((int) d);
}

