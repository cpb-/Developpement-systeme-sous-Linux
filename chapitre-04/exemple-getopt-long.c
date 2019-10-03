// ------------------------------------------------------------------
// exemple-getpopt-long.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int	speed = 0; /* -1 = lent, 0 = normal, 1 = rapide */

int main (int argc, char *argv[])
{
	char *optstring = "b:e:";

	struct option longopts[] = {

		/* name  has_arg  flag     val  */

		{ "begin",  1,    NULL,    'b' },
		{ "end",    1,    NULL,    'e' },
		{ "slow",   0,    &speed,   1  },
		{ "fast",   0,    &speed,  -1  },

		/* Le dernier element doit etre nul */
		{ NULL,     0,    NULL,     0  },
	};

	int	longindex;

	int	option;

	int	begin_position = 0;
	int end_position = 999;

	while ((option = getopt_long(argc, argv,
			optstring, longopts, &longindex)) != -1) {

		switch (option) {

			case 'b' :
				if (sscanf(optarg, "%d", &begin_position) != 1) {
					fprintf(stderr, "Begin position error\n");
				};
				break;

			case 'e' :
				if (sscanf(optarg, "%d", &end_position) != 1) {
					fprintf(stderr, "End position error\n");
				};
				break;

			case 0 :
				break;

			case '?' :
				/*  On a laisse opterr à 1 */
				break;
		}
	}
	fprintf(stdout, "Speed %d, begin at %d, end at %d\n",
			speed, begin_position, end_position);
	return 0;
}
