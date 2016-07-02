// ------------------------------------------------------------------
// exemple-getpopt-long.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

	#include <stdio.h>
	#include <stdlib.h>
	#include <getopt.h>

	int	vitesse_lecture = 0; /* -1 = lent, 0 = normal, 1 = rapide */

int main (int argc, char * argv [])
{
	char * optstring = "d:f:";
	
	struct option longopts[] = {

		/* name  has_arg  flag                 val   */
	
		{ "debut",  1,    NULL,               'd' },
		{ "fin",    1,    NULL,               'f' },	
		{ "rapide", 0,    & vitesse_lecture,   1  },
		{ "lent",   0,    & vitesse_lecture,  -1  },

		/* Le dernier element doit etre nul */
		{ NULL,     0,    NULL,                0  },
	};

	int	longindex;

	int	option;

	int	debut = 0;
	int 	fin = 999;

	while ((option = getopt_long(argc, argv, 
			optstring, longopts, & longindex)) != -1) {

		switch (option) {

			case 'd' :
				if (sscanf(optarg, "%d", & debut) != 1) {
					fprintf(stderr, "Erreur pour debut\n");
				};
				break;
			
			case 'f' :
				if (sscanf(optarg, "%d", & fin) != 1) {
					fprintf(stderr, "Erreur pour fin\n");
				};
				break;

			case 0 :
				/* vitesse_lecture traitee automatiquement */
				break;
			case '?' :
				/*  On a laisse opterr à 1 */
				break;
		}
	}
	fprintf(stdout, "Vitesse %d, debut %d, fin %d\n",
			vitesse_lecture, debut, fin);
	return 0;
}
