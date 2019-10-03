// ------------------------------------------------------------------
// exemple-fcntl-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	int status;

	status = fcntl(STDIN_FILENO, F_GETFL) & O_ACCMODE;
	fprintf(stderr, "stdin : %s\n",
	        (status == O_RDWR) ? "R/W" : (status == O_RDONLY) ? "R" : "W");
	status = fcntl(STDOUT_FILENO, F_GETFL) & O_ACCMODE;
	fprintf(stderr, "stdout : %s\n",
	        (status == O_RDWR) ? "R/W" : (status == O_RDONLY) ? "R" : "W");
	status = fcntl(STDERR_FILENO, F_GETFL) & O_ACCMODE;
	fprintf(stderr, "stderr : %s\n",
	        (status == O_RDWR) ? "R/W" : (status == O_RDONLY) ? "R" : "W");
	
	return EXIT_SUCCESS;
}
