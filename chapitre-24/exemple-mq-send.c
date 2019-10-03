// ------------------------------------------------------------------
// exemple-mq_send.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
	mqd_t mq;
	int  priority;

	if (argc != 4) {
		fprintf(stderr, "Syntaxe : %s file priority message\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((mq = mq_open(argv[1], O_WRONLY | O_CREAT, 0644, NULL)) == (mqd_t) -1) {
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	if (sscanf(argv[2], "%d", & priority) != 1) {
		fprintf(stderr, "Priorite invalide : %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	if (mq_send(mq, argv[3], strlen(argv[3]), priority) != 0) {
		perror("mq_send");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
