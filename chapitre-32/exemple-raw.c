// ------------------------------------------------------------------
// exemple-raw.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

struct termios saved_termios;

int    keyboard_init(int fd);
int    keyboard_restore(int fd);

int main (void)
{
	char c = 0;
	int  i = 0;
	char *string = "-\\|/";

	keyboard_init(STDIN_FILENO);
	while (1) {
		if (read(STDIN_FILENO, & c, 1) == 1)
			if (c == 'q')
				break;
		fprintf(stdout, "\r%c (%02X)", string[i], c);
		fflush(stdout);
		if (string[++i] == '\0')
			i = 0;
		usleep(100000);
	}
	keyboard_restore(STDIN_FILENO);

	return EXIT_SUCCESS;
}

int keyboard_init (int fd)
{
	struct termios configuration;

	if (tcgetattr(fd, &configuration) != 0)
		return -1;
	memcpy(&saved_termios, &configuration, sizeof(struct termios));
	cfmakeraw(&configuration);
	configuration.c_cc[VMIN] = 0;
	if (tcsetattr(fd, TCSANOW, &configuration) != 0)
		return -1;

	return 0;
}

int keyboard_restore(int fd)
{
	tcsetattr(fd, TCSANOW, &saved_termios);

	return 0;
}

