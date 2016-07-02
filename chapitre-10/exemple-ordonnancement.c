// ------------------------------------------------------------------
// exemple-ordonnancement.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (int argc, char * argv[])
{
	int                 i;
	int                 pid;
	int                 ordonnancement;
	struct sched_param  param;
	struct timespec     intervalle;

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "%s: ", argv[i]);
		if ((sscanf(argv[i], "%d", & pid) != 1)
		 || (ordonnancement = sched_getscheduler(pid)) < 0) {
			fprintf(stdout, "invalide\n");
			continue;
		}
		switch(ordonnancement) {
			case SCHED_OTHER :
				fprintf(stdout, "OTHER priorite (nice) %d\n",
					getpriority(PRIO_PROCESS, pid));
				break;
			case SCHED_FIFO :
				sched_getparam(pid, & param);
				fprintf(stdout, "FIFO priorite %d\n",
					param.sched_priority);
				break;
			case SCHED_RR :
				sched_getparam(pid, & param);
				sched_rr_get_interval(pid, & intervalle);
				fprintf(stdout, "RR priorite %d, intervalle %ld ns\n",
					param.sched_priority,
					intervalle.tv_sec * 1000000000 + intervalle.tv_nsec);
				break;
			default :
				fprintf(stdout, "???\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}

