// ------------------------------------------------------------------
// exemple-mq-receive.c
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
	int    n;
	mqd_t  mq;
	struct mq_attr attr;
	char * buffer = NULL;
	unsigned int priority;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((mq = mq_open(argv[1], O_RDONLY)) == (mqd_t) -1) {
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	if (mq_getattr(mq, & attr) != 0) {
		perror("mq_getattr");
		exit(EXIT_FAILURE);
	}
	if ((buffer = malloc(attr.mq_msgsize)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if ((n = mq_receive(mq, buffer, attr.mq_msgsize, &priority)) < 0) {
		perror("mq_send");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "[%d] %s\n", priority, buffer);

	return EXIT_SUCCESS;
}
