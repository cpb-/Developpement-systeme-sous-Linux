// ------------------------------------------------------------------
// exemple-signal-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------
#define	_XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void gestionnaire (int numero)
{
	int i;
	signal(numero, gestionnaire);
	fprintf(stdout, "debut du gestionnaire de signal %d\n", numero);
	for (i = 1; i < 4; i ++) {
		fprintf(stdout, "%d\n", i);
		sleep(1);
	}
	fprintf(stdout, "fin du gestionnaire de signal %d\n", numero); 
}

int main (void)
{
	signal(SIGUSR1, gestionnaire);
	
	if (fork() == 0) {
		kill(getppid(), SIGUSR1);
		sleep(1);
		kill(getppid(), SIGUSR1);
	} else {
		while (1)
			pause();
	}
	return EXIT_SUCCESS;	
}

