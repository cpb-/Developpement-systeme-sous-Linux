// ------------------------------------------------------------------
// exemple-boucle-temps-reel.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	struct sched_param param;

	param.sched_priority = 99;
	if (sched_setscheduler(0, SCHED_FIFO, & param) != 0) {
		perror("SCHED_FIFO");
		exit(1);
	}

	alarm(20); // On recevra SIGALRM dans 20 secondes
	while (1)
		;
	return 0;
}

