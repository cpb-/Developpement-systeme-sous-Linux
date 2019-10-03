// ------------------------------------------------------------------
// exemple-getpriority.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void syntax (char * nom)
{
	fprintf(stderr, "Syntax : %s <class> <ident> \n", nom);
	fprintf(stderr, "   <class> = P (PID)\n");
	fprintf(stderr, "             G (PGID)\n");
	fprintf(stderr, "             U (UID)\n");
	exit(EXIT_FAILURE);
}

int main (int argc, char * argv[])
{
	int  class;
	int  id;
	int  priority;

	if (argc != 3)
		syntax(argv[0]);
	if (toupper(argv[1][0]) == 'P')
		class = PRIO_PROCESS;
	else if (toupper(argv[1][0]) == 'G')
		class = PRIO_PGRP;
	else if (toupper(argv[1][0]) == 'U')
		class = PRIO_USER;
	else
		syntax(argv[0]);
	if (sscanf(argv[2], "%d", &id) != 1)
		syntax(argv[0]);
	errno = 0;
	priority = getpriority(class, id);
	if ((priority == -1) && (errno != 0))
		perror(argv[2]);
	else
		fprintf(stderr, "%d : %d\n", id, priority);
	return EXIT_SUCCESS;
}

