// ------------------------------------------------------------------
// exemple-getprotoby.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv [])
{
	int    i, j;
	int    number;
	struct protoent *proto;

	for (i = 1; i < argc; i ++) {
		if (sscanf(argv[i], "%d", &number) == 1)
			proto = getprotobynumber(number);
		else
			proto = getprotobyname(argv[i]);
		fprintf(stdout, "%s : ", argv[i]);
		if (proto == NULL) {
			fprintf(stdout, "inconnu \n");
			continue;
		}
		fprintf(stdout, "%s ( ", proto->p_name);
		for (j = 0; proto->p_aliases[j] != NULL; j ++)
			fprintf(stdout, "%s ", proto->p_aliases[j]);
		fprintf(stdout, ") number = %d \n", proto->p_proto);
	}

	return EXIT_SUCCESS;
}

