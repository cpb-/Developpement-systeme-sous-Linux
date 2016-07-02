// ------------------------------------------------------------------
// exemple-sigqueue-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NB_SIGNAUX 10
int	signal_arrive[NB_SIGNAUX];
int	valeur_arrivee[NB_SIGNAUX];
int	nb_signaux_arrives = 0;

void gestionnaire_signal_temps_reel (int numero, siginfo_t * info, void * inutile)
{
	assert(nb_signaux_arrives < NB_SIGNAUX);
	signal_arrive[nb_signaux_arrives] = numero - SIGRTMIN;
	valeur_arrivee[nb_signaux_arrives]  = info->si_value.sival_int;
	nb_signaux_arrives ++;
}

void envoie_signal_temps_reel (int numero, int valeur)
{
	union sigval valeur_sig;

	fprintf(stdout, "Envoi signal SIRTMIN+%d, valeur %d\n",
	                  numero, valeur);
	valeur_sig.sival_int = valeur;
	if (sigqueue(getpid(), numero + SIGRTMIN, valeur_sig) < 0) {
		perror("sigqueue");
		exit(EXIT_FAILURE);
	}
}

int main (void)
{
	int i;
	sigset_t ensemble;
	struct sigaction action;

	fprintf(stdout, "Installation gestionnaires de signaux\n");
	action.sa_sigaction = gestionnaire_signal_temps_reel;
	sigfillset(& action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGRTMIN + 1, & action, NULL) < 0)
	 || (sigaction(SIGRTMIN + 2, & action, NULL) < 0)
	 || (sigaction(SIGRTMIN + 3, & action, NULL) < 0)) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	
	fprintf(stdout, "Blocage de tous les signaux\n");
	sigfillset(& ensemble);
	sigprocmask(SIG_BLOCK, & ensemble, NULL);

	envoie_signal_temps_reel(1, 0);
	envoie_signal_temps_reel(2, 1);
	envoie_signal_temps_reel(3, 2);
	envoie_signal_temps_reel(1, 3);
	envoie_signal_temps_reel(2, 4);
	envoie_signal_temps_reel(3, 5);
	envoie_signal_temps_reel(3, 6);
	envoie_signal_temps_reel(2, 7);
	envoie_signal_temps_reel(1, 8);
	envoie_signal_temps_reel(3, 9);
	
	fprintf(stdout, "Deblocage de tous les signaux\n");
	sigfillset(& ensemble);
	sigprocmask(SIG_UNBLOCK, & ensemble, NULL);

	fprintf(stdout, "Affichage des resultats\n");
	for (i = 0; i < nb_signaux_arrives; i ++)
		fprintf(stdout, "Signal SIGRTMIN+%d, valeur %d\n",
                        signal_arrive[i], valeur_arrivee[i]);
	return(EXIT_SUCCESS);
}

