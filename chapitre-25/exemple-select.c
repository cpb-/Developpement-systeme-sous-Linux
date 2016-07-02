// ------------------------------------------------------------------
// exemple-select.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2016 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define	NB_FILS	10

int main (void)
{
	int tube[NB_FILS][2];
	int i;
	int max = -1;
	char c;
	fd_set ensemble;

	for (i = 0; i < NB_FILS; i ++) {
		if (pipe (tube[i]) < 0) {
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		if (fork() == 0) {
			// Fils
			close(tube[i][0]);
			c = '0' + i;
			while(1) {
				sleep(i + 1);
				write(tube[i][1], & c, 1);
			}
		}
		close(tube[i][1]);
	}
	// Père
	while (1) {
		FD_ZERO(& ensemble);
		for (i = 0; i < NB_FILS; i ++) {
			FD_SET(tube[i][0], & ensemble);
			if (tube[i][0] > max)
				max = tube[i][0];
		}
		if (select(max, & ensemble, NULL, NULL, NULL) <= 0) {
			perror("select");
			break;
		}
		for (i = 0; i < NB_FILS; i ++) {
		 	if (FD_ISSET(tube[i][0], & ensemble)) {
				read(tube[i][0], & c, 1);
				fprintf(stderr, "%d ", i);
			}
		}
	}
	return EXIT_SUCCESS;
}

