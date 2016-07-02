// ------------------------------------------------------------------
// exemple-syslog.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main (int argc, char * argv[])
{
	int 	i;

	openlog(argv[0], LOG_PID, LOG_USER);
	for (i = 1; i < argc; i ++)
		syslog(LOG_INFO, argv[i]);
	closelog();
	return EXIT_SUCCESS;
}

