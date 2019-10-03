// ------------------------------------------------------------------
// exemple-serie.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	int 	fd;
	char	string[2];

	if (argc != 2) {
		fprintf (stderr, "%s <fichier special>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "Nous allons verifier la tension entre les broches :\n"
			 "  7 (-) et 20 (+) pour un connecteur DB-25 \n"
			 "  5 (-) et  4 (+) pour un connecteur DB-9 \n \n ");

	fprintf(stdout, "La tension doit etre inferieure a -3 V \n");
	fprintf(stdout, "Pressez Entree pour continuer\n");
	fgets(string, 2, stdin);

	fd = open(argv[1], O_RDONLY | O_NONBLOCK);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "La tension doit etre superieure a +3 V\n");
	fprintf(stdout, "Pressez Entree pour continuer\n");
	fgets(string, 2, stdin);

	fprintf(stdout, "La tension doit etre a nouveau < -3 V\n");
	if (close(fd) < 0) {
		perror ("close");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

