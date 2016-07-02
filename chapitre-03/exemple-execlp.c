// ------------------------------------------------------------------
// exemple-execlp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv [])
{
	char compteur[2];
	int i;

	i = 0;
	if (argc == 2)
		sscanf(argv[1], "%d", & i);

	if (i < 5) {
		i ++;
		sprintf(compteur, "%d", i);

		fprintf(stdout, "execlp(%s, %s, %s, NULL)\n",
		        argv[0], argv[0], compteur);
		execlp(argv[0], argv[0], compteur, (char *) NULL);
	}
	return 0;
}
