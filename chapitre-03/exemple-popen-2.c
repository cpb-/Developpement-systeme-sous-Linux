// ------------------------------------------------------------------
// exemple-popen-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main (void)
{
	FILE * sortie;
	char ligne [128];
	char etat  [128];

	if ((sortie = popen("/sbin/ifconfig eth0", "r")) == NULL) {
		fprintf(stderr, " Erreur popen %d \n", errno);
		exit(1);
	}
	while (fgets(ligne, 127, sortie) != NULL) {
		if (sscanf(ligne, "%s", etat) == 1)
			if (strcmp(etat, "UP") == 0) {
				fprintf(stderr, "interface eth0 en marche \n");
				pclose(sortie);
				return 0;
			}
	}
	fprintf(stdout, "interface eth0 inactive \n");
	pclose(sortie);
	return 0;
}
