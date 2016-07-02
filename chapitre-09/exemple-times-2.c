// ------------------------------------------------------------------
// exemple-times-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

int main (int argc, char * argv[])
{
	struct tms mesure;
	double duree_ecoulee;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s <commande> \n", argv [0]);
		exit(EXIT_FAILURE);
	}
	system(argv[1]);
	times(& mesure);
	duree_ecoulee = (double) mesure.tms_cutime / sysconf(_SC_CLK_TCK);
	fprintf(stdout, "Temps CPU mode utilisateur = %f \n", duree_ecoulee);
	duree_ecoulee = (double) mesure.tms_cstime / sysconf(_SC_CLK_TCK);
	fprintf(stdout, "Temps CPU en mode noyau    = %f \n", duree_ecoulee);
	return EXIT_SUCCESS;
}

