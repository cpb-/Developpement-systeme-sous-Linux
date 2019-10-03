// ------------------------------------------------------------------
// exemple-popen-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main (void)
{
	FILE * fp;
	char * cmd;

	if ((cmd = malloc(strlen(getlogin()) + 6)) == NULL) {
		fprintf(stderr, "Error in malloc(): %d\n", errno);
		exit(1);
	}

	strcpy(cmd, "mail ");
	strcat(cmd, getlogin());

	if ((fp = popen(cmd, "w")) == NULL) {
		fprintf(stderr, " Error in popen(): %d \n", errno);
		exit(1);
	}

	fprintf(fp, "Ceci est un message \n");
	fprintf(fp, "emis par moi-meme\n");
	pclose(fp);

	return 0;
}

