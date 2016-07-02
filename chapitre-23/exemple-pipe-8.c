// ------------------------------------------------------------------
// exemple-pipe-8.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main (void)
{
	int	tube[2];
	struct stat status;

	fprintf(stdout, "Creation tube\n");
	if (pipe(tube) != 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if (fstat(tube[0], & status) != 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	fprintf (stdout, "Status : ");
	if (S_ISFIFO(status.st_mode))
		fprintf(stdout, "FIFO\n");
	else
		fprintf(stdout, "? \n");
	return EXIT_SUCCESS;
}

