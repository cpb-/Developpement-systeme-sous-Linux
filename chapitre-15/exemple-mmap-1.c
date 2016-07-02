// ------------------------------------------------------------------
// exemple-mmap-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main (int argc, char * argv[])
{
	int     i;
	int     fd;
	char    tmp;
	char *  projection;
	long    taille_fichier;
	struct stat etat_fichier;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s fichier_a_inverser\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDWR)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, & etat_fichier) != 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	taille_fichier = etat_fichier.st_size;
	projection = (char *) mmap(NULL, taille_fichier,
				PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (projection == (char *) MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	close(fd);
	for (i = 0; i < taille_fichier / 2; i ++) {
		tmp = projection[i];
		projection[i ] = projection[taille_fichier - i - 1];
		projection[taille_fichier - i - 1] = tmp;
	}
	munmap((void *) projection, taille_fichier);
	return EXIT_SUCCESS;
}

