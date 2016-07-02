// ------------------------------------------------------------------
// exemple-raw.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

struct termios sauvegarde;

int    initialisation_clavier (int fd);
int    restauration_clavier   (int fd);

int main (void)
{
	char c = 0;
	int  i = 0;
	char * chaine = "-\\|/";

	initialisation_clavier(STDIN_FILENO);
	while (1) {
		if (read(STDIN_FILENO, & c, 1) == 1)
			if (c == 'q')
				break;
		fprintf(stdout, "\r%c (%02X)", chaine[i], c);
		fflush(stdout);
		if (chaine[++ i] == '\0')
			i = 0;
		usleep(100000);
	}
	restauration_clavier(STDIN_FILENO);
	return EXIT_SUCCESS;
}

int initialisation_clavier (int fd)
{
	struct termios configuration;
	if (tcgetattr(fd, & configuration) != 0)
		return -1;
	memcpy(& sauvegarde, & configuration, sizeof(struct termios));
	cfmakeraw(& configuration);
	configuration.c_cc[VMIN] = 0;
	if (tcsetattr(fd, TCSANOW, & configuration) != 0)
		return -1;
	return 0;
}

int restauration_clavier (int fd)
{
	tcsetattr(fd, TCSANOW, & sauvegarde);
	return 0;
}

