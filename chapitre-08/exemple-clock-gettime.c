// ------------------------------------------------------------------
// exemple-clock-gettime-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

int main (void)
{
	struct timespec ts;

	if (clock_gettime(CLOCK_REALTIME, &ts) != 0)
		perror("CLOCK_REALTIME");
	else
		printf("CLOCK_REALTIME : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

	if (clock_gettime(CLOCK_REALTIME_COARSE, &ts) != 0)
		perror("CLOCK_REALTIME_COARSE");
	else
		printf("CLOCK_REALTIME_COARSE : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
		perror("CLOCK_MONOTONIC");
	else
		printf("CLOCK_MONOTONIC : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

	if (clock_gettime(CLOCK_MONOTONIC_COARSE, &ts) != 0)
		perror("CLOCK_MONOTONIC_COARSE");
	else
		printf("CLOCK_MONOTONIC_COARSE : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

	if (clock_gettime(CLOCK_MONOTONIC_RAW, &ts) != 0)
		perror("CLOCK_MONOTONIC_RAW");
	else
		printf("CLOCK_MONOTONIC_RAW : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

	if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts) != 0)
		perror("CLOCK_PROCESS_CPUTIME_ID");
	else
		printf("CLOCK_PROCESS_CPUTIME_ID : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

	if (clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts) != 0)
		perror("CLOCK_THREAD_CPUTIME_ID");
	else
		printf("CLOCK_THREAD_CPUTIME_ID : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);

	if (clock_gettime(CLOCK_BOOTTIME, &ts) != 0)
		perror("CLOCK_BOOTTIME");
	else
		printf("CLOCK_BOOTTIME : %ld.%09ld\n", ts.tv_sec, ts.tv_nsec);


	return 0;
}

