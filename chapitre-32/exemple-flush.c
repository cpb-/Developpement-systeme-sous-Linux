// ------------------------------------------------------------------
// exemple-flush.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main (void)
{
	struct termios config;
	int i;

	fprintf(stdout, "FLUSH dans 5 secondes\n");
	sleep(5);
	fprintf(stdout, "FLUSH !\n");
	if (tcgetattr(STDIN_FILENO, &config) == 0)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &config);
	while ((i = fgetc(stdin)) != EOF)
		fprintf(stdout, "%02X ", i);

	return EXIT_SUCCESS;
}

