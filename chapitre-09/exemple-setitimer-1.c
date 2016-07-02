// ------------------------------------------------------------------
// exemple-setitimer-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>

unsigned long int       mode_utilisateur;
unsigned long int       mode_utilisateur_et_noyau;

void    gestionnaire_signaux    (int numero);
void    action_a_mesurer        (void);

int main (void)
{
	struct itimerval timer;

	/* Preparation du timer */
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 10000; /* 1/100 s. */
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 10000; /* 1/100 s. */

	/* Installation du gestionnaire de signaux */
	signal(SIGVTALRM, gestionnaire_signaux);
	signal(SIGPROF, gestionnaire_signaux);
	/* Programmation des timers */
	if ((setitimer(ITIMER_VIRTUAL, & timer, NULL) != 0)
	 || (setitimer(ITIMER_PROF, & timer, NULL) != 0)) {
		fprintf(stderr, "Erreur dans setitimer \n");
		return EXIT_FAILURE;
	}	
	/* Appel de la routine de travail effectif du processus */
	action_a_mesurer();

	/* Desinstallation des timers */
	setitimer(ITIMER_VIRTUAL, NULL, NULL);
	setitimer(ITIMER_PROF, NULL, NULL);
	fprintf(stdout, "Temps passe en mode utilisateur : %ld/100 s \n",
		mode_utilisateur);
	fprintf(stdout, "Temps passe en mode noyau : %ld/100 s \n",
		mode_utilisateur_et_noyau - mode_utilisateur);
	return EXIT_SUCCESS;
}

void gestionnaire_signaux (int numero)
{
	if (numero == SIGVTALRM)
		mode_utilisateur ++;
	else 
		mode_utilisateur_et_noyau ++;
}


void action_a_mesurer (void)
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


