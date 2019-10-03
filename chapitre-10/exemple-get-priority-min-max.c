// ------------------------------------------------------------------
// exemple-get-priority-min-max.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	fprintf(stdout, "Scheduling FIFO :\n  %d <= prio <= %d\n",
		sched_get_priority_min(SCHED_FIFO),
		sched_get_priority_max(SCHED_FIFO));
	fprintf(stdout, "Scheduling RR :\n  %d <= prio <= %d\n",
		sched_get_priority_min(SCHED_RR),
		sched_get_priority_max(SCHED_RR));
	fprintf(stdout, "Scheduling OTHER :\n  %d <= prio <= %d\n",
		sched_get_priority_min(SCHED_OTHER),
		sched_get_priority_max(SCHED_OTHER));
	return EXIT_SUCCESS;
}
