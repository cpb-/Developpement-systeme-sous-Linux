// ------------------------------------------------------------------
// exemple-popen-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define INTERFACE "eth0"

int main (void)
{
	FILE * fp;
	char line[128];

	if ((fp = popen("ip link show " INTERFACE, "r")) == NULL) {
		fprintf(stderr, " Error in popen(): %d \n", errno);
		exit(1);
	}
	while (fgets(line, 127, fp) != NULL) {
		if (strstr(line, "state UP") != NULL) {
			fprintf(stdout, "interface " INTERFACE " en marche \n");
			pclose(fp);
			return 0;
		}
	}
	fprintf(stdout, "interface " INTERFACE " inactive \n");
	pclose(fp);

	return 0;
}
