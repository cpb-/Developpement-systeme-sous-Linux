// ------------------------------------------------------------------
// exemple-getopt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>

int main (int argc, char * argv [])
{

	char *	liste_options = "abc:XY";
	int	option;

	opterr = 0; /* Pas de message d'erreur automatique */

	while ((option = getopt(argc, argv, liste_options)) != -1) {
		
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
				fprintf(stderr, "Option %c fausse\n", optopt);
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
