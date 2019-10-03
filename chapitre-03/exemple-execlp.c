// ------------------------------------------------------------------
// exemple-execlp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv [])
{
	char counter[2];
	int i;

	i = 0;
	if (argc == 2)
		sscanf(argv[1], "%d", & i);

	if (i < 5) {
		i ++;
		sprintf(counter, "%d", i);

		fprintf(stdout, "execlp(%s, %s, %s, NULL)\n",
		        argv[0], argv[0], counter);
		execlp(argv[0], argv[0], counter, (char *) NULL);
	}
	return 0;
}
