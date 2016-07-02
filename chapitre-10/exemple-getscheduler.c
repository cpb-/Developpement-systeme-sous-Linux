// ------------------------------------------------------------------
// exemple-getscheduler.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	int i;
	int ordonnancement;
	int pid;

	for (i = 1; i < argc; i ++) {
		fprintf (stdout, "%s : ", argv[i]);
    		if ((sscanf(argv[i], "%d", & pid) != 1)
		 || ((ordonnancement = sched_getscheduler(pid)) < 0)) {
			fprintf(stdout, "invalide\n");
			continue;
		}
		switch (ordonnancement) {
			case SCHED_RR :    fprintf(stdout, "RR \n");   break;
			case SCHED_FIFO :  fprintf(stdout, "FIFO\n");  break;
			case SCHED_OTHER : fprintf(stdout, "OTHER\n"); break;
			default :          fprintf(stdout, "???\n");   break;
		}
	}
	return EXIT_SUCCESS;
}

