// ------------------------------------------------------------------
// exemple-setitimer-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>

unsigned long int  user;
unsigned long int  user_and_kernel;

void signal_handler(int signum);
void function_to_profile(void);

int main (void)
{
	struct itimerval timer;

	/* Preparation du timer */
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 10000; /* 1/100 s. */
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 10000; /* 1/100 s. */

	/* Installation du gestionnaire de signaux */
	signal(SIGVTALRM, signal_handler);
	signal(SIGPROF, signal_handler);
	/* Programmation des timers */
	if ((setitimer(ITIMER_VIRTUAL, &timer, NULL) != 0)
	 || (setitimer(ITIMER_PROF, &timer, NULL) != 0)) {
		fprintf(stderr, "Error during setitimer \n");
		return EXIT_FAILURE;
	}	
	/* Appel de la routine de travail effectif du processus */
	function_to_profile();

	/* Desinstallation des timers */
	setitimer(ITIMER_VIRTUAL, NULL, NULL);
	setitimer(ITIMER_PROF, NULL, NULL);
	fprintf(stdout, "User mode time : %ld/100 s \n",
		user);
	fprintf(stdout, "Kernel mode time : %ld/100 s \n",
		user_and_kernel - user);
	return EXIT_SUCCESS;
}

void signal_handler(int signum)
{
	if (signum == SIGVTALRM)
		user ++;
	else 
		user_and_kernel ++;
}


void function_to_profile(void)
{
	int i, j;
	FILE * fp1, * fp2;
	double x = 0.0;

	for (i = 0; i < 30000; i ++)
		for (j = 0; j < 30000; j ++)
			x += i * j;
	for (i = 0; i < 50000; i ++) {
		if ((fp1 = fopen ("exemple_setitimer_2", "r")) != NULL) {
			if ((fp2 = fopen("/dev/null", "w")) != NULL) {
				while (fread(& j, sizeof (int), 1, fp1) == 1)
					fwrite(& j, sizeof (int), 1, fp2);
				fclose(fp2);
			}
			fclose(fp1);
		}
	}
}


