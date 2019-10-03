// ------------------------------------------------------------------
// exemple-getopt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>

int main (int argc, char * argv[])
{

	char *opt_list = "abc:XY";
	int   option;

	opterr = 0; /* Pas de message d'erreur automatique */

	while ((option = getopt(argc, argv, opt_list)) != -1) {
		switch (option) {

			case 'a' :
				fprintf(stdout, "Option a\n");
				break;
			case 'b' :
				fprintf(stdout, "Option b\n");
				break;
			case 'c' :
				fprintf(stdout, "Option c %s\n", optarg);
				break;
			case 'X' :
			case 'Y' :
				fprintf(stdout, "Option %c\n", option);
				break;
			case '?' :
				fprintf(stderr, "Wrong option %c\n", optopt);
				break;
		}
	}

	if (optind != argc) {
		fprintf(stdout, "Arguments restants :\n");
		while (optind != argc)
			fprintf(stdout, "  %s\n", argv[optind ++]);
	}

	return 0;
}
