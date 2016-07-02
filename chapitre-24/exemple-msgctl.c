// ------------------------------------------------------------------
// exemple-msgctl.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main (int argc, char * argv[])
{
	key_t     key;
	int       file;
	
	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s fichier_cle \n",
				argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((key = ftok(argv[1], 0)) == -1) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	if ((file = msgget(key, 0)) == -1)
		exit(EXIT_SUCCESS);
	msgctl(file, IPC_RMID, NULL);
	return EXIT_SUCCESS;
}
