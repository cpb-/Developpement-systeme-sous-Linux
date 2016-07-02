// ------------------------------------------------------------------
// exemple-flush.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main (void)
{
	struct termios terminal;
	int i;

	fprintf(stdout, "FLUSH dans 5 secondes\n");
	sleep(5);
	fprintf(stdout, "FLUSH !\n");
	if (tcgetattr(STDIN_FILENO, & terminal) == 0)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, & terminal);
	while ((i = fgetc(stdin)) != EOF)
		fprintf(stdout, "%02X ", i);
	return EXIT_SUCCESS;
}

