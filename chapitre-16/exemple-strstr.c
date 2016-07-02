// ------------------------------------------------------------------
// exemple-strstr.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
	int	   i;
	char * chaine;

	if (argc != 3) {
		fprintf (stderr, "Syntaxe : %s chaine sous-chaine\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (strlen(argv[2]) == 0) {
		fprintf(stderr, "La sous-chaine recherchee est vide !\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	chaine = argv[1];
	while (1) {
		chaine = strstr(chaine, argv[2]);
		if (chaine == NULL)
			break;
		/* on saute la sous-chaine trouvee */
		chaine += strlen(argv[2]);
		i ++;
	}
	if (i == 0)
		fprintf(stdout, "%s ne se trouve pas dans %s\n",
				argv[2], argv[1]);
	else
		fprintf(stdout, "%s a ete trouvee %d fois dans %s\n",
				argv[2], i, argv[1]);

	return EXIT_SUCCESS;
}

