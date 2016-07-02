// ------------------------------------------------------------------
// exemple-nonblock-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int  tube[2];
	char c = 'c';
	int  i;

	if (pipe(tube) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	fcntl(tube[1], F_SETFL, O_NONBLOCK);
	i = 0;
	while (1) {
		if (write(tube[1], & c, 1) != 1) {
			perror("write");
			sleep(1);
		} else
			i ++;
		fprintf(stdout, "%d octets ecrits\n", i);
	}
	return EXIT_SUCCESS;
}
