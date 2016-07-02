// ------------------------------------------------------------------
// exemple-nonblock-2.c
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
	char c;

	if (pipe(tube) !=0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	switch (fork()) {
		case -1 :
			perror("fork");
			exit(EXIT_FAILURE);
		case 0 : /* fils : ecriture */
			close(tube[0]);
			while (1) {
				write(tube[1], & c, 1);
				usleep(700000);
			}
		default : /* pere : lecture */
			close(tube[1]);
			fcntl(tube[0], F_SETFL, O_NONBLOCK);
			while (1) {
				if (read(tube[0], & c, 1) == 1) 
					printf("Ok\n");
				else
					printf("Non\n");
				usleep(100000);
			}
	}
	return EXIT_SUCCESS;
}

