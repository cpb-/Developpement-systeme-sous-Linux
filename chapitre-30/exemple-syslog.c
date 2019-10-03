// ------------------------------------------------------------------
// exemple-syslog.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main (int argc, char * argv[])
{
	int 	i;

	openlog(argv[0], LOG_PID, LOG_USER);
	for (i = 1; i < argc; i ++)
		syslog(LOG_INFO, "%s", argv[i]);
	closelog();

	return EXIT_SUCCESS;
}

