// ------------------------------------------------------------------
// exemple-msgsnd.c
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

typedef struct {
	long type;
	char texte [256];
} message_t;

int main (int argc, char * argv[])
{
	key_t     key;
	message_t message;
	int       file;
	
	if (argc != 4) {
		fprintf(stderr, "Syntaxe : %s fichier_cle type message \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((key = ftok(argv[1], 0)) == -1) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	if ((sscanf(argv[2], "%ld", & (message.type)) != 1)
	 || (message.type <= 0)) {		
		fprintf(stderr, "Type invalide");
		exit(EXIT_FAILURE);
	}
	strncpy(message.texte, argv[3], 255);
	message.texte[255] = '\0';
	if ((file = msgget(key, IPC_CREAT | 0600)) == -1) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	if (msgsnd(file, (void *) & message, 256, 0) <0) {
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}
