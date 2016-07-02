// ------------------------------------------------------------------
// exemple-write.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>

#define TAILLE_BLOC	1024
#define DEPASSEMENT	767


void gestionnaire (int numero)
{
	fprintf(stderr, "Signal %d recu : %s\n", numero, strsignal(numero));
}

int main (void)
{
	struct rlimit   limite;
	int                 fd;
	char bloc[TAILLE_BLOC];
	int          nb_ecrits;

	signal(SIGXFSZ, gestionnaire);

	if (getrlimit(RLIMIT_FSIZE, & limite) != 0) {
		perror("getrlimit");
		exit(EXIT_FAILURE);
	}
	limite.rlim_cur = 3 * TAILLE_BLOC + DEPASSEMENT;
	if (setrlimit(RLIMIT_FSIZE, & limite) != 0) {
		perror("setrlimit");
		exit(EXIT_FAILURE);
	}
	fd = open("essai.write", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	memset(bloc, 1, TAILLE_BLOC);
	do {
		nb_ecrits = write(fd, bloc, TAILLE_BLOC);
		if (nb_ecrits != TAILLE_BLOC) {
			fprintf(stderr, "nb_ecrits = %d\n", nb_ecrits);
			if (errno != 0) {
				fprintf(stderr, "errno = %d : ", errno);
				perror("");
			}
		}
	} while (nb_ecrits != -1);
	close(fd);
	return EXIT_SUCCESS;
}

