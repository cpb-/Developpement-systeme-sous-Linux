// ------------------------------------------------------------------
// exemple-rusage.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main (int argc, char * argv[])
{
	int lesquelles;
	struct rusage statistiques;

	if (argc == 1) {
		lesquelles = RUSAGE_SELF;
	} else {
		system(argv[1]);
		lesquelles = RUSAGE_CHILDREN;
	}
	if (getrusage(lesquelles, & statistiques) != 0) {
		fprintf(stderr, "Impossible d'obtenir les statistiques \n");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Temps en mode utilisateur  %ld s. et %ld ms \n",
	        statistiques.ru_utime.tv_sec,
	        statistiques.ru_utime.tv_usec / 1000);
	fprintf(stdout, "Temps en mode noyau        %ld s. et %ld ms \n",
	        statistiques.ru_stime.tv_sec,
	        statistiques.ru_stime.tv_usec / 1000);
	fprintf(stdout, "\n");
	fprintf(stdout, "Nombre de fautes de pages mineures : %ld \n",
	        statistiques.ru_minflt);
	fprintf(stdout, "Nombre de fautes de pages majeures : %ld \n",
	        statistiques.ru_majflt);
	fprintf(stdout, "Nombre de swaps du processus       : %ld \n",
	        statistiques.ru_nswap);
	return EXIT_SUCCESS;
}
