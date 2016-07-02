// ------------------------------------------------------------------
// exemple-fcntl-2.c
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
	int etat;
	etat = fcntl(STDIN_FILENO, F_GETFL) & O_ACCMODE;
	fprintf(stderr, "stdin : %s\n",
	        (etat == O_RDWR) ? "R/W" : (etat == O_RDONLY) ? "R" : "W");
	etat = fcntl(STDOUT_FILENO, F_GETFL) & O_ACCMODE;
	fprintf(stderr, "stdout : %s\n",
	        (etat == O_RDWR) ? "R/W" : (etat == O_RDONLY) ? "R" : "W");
	etat = fcntl(STDERR_FILENO, F_GETFL) & O_ACCMODE;
	fprintf(stderr, "stderr : %s\n",
	        (etat == O_RDWR) ? "R/W" : (etat == O_RDONLY) ? "R" : "W");
	return EXIT_SUCCESS;
}
