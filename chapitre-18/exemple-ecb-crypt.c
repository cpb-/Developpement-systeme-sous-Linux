// ------------------------------------------------------------------
// exemple-ecb-crypt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <rpc/des_crypt.h>

int main (int argc, char * argv[])
{
	char *  nom_programme;
	int     fichier;
	struct stat	etat_fichier;
	long     taille_fichier;
	char *   projection;
	char     cle [8];
	unsigned mode;
	int      retour;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe %s : fichier clé\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	nom_programme = basename(argv[0]);
	if (strcasecmp(nom_programme, "des-decrypte") == 0)
		mode = DES_DECRYPT;
	else
		mode = DES_ENCRYPT;

	if ((fichier = open(argv[1], O_RDWR)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (stat(argv[1], & etat_fichier) != 0) {
		perror("stat");
		exit(EXIT_FAILURE);
	}
	taille_fichier = etat_fichier.st_size;
	taille_fichier = ((taille_fichier + 7) >> 3) << 3;
	projection = (char *) mmap(NULL, taille_fichier, 
				PROT_READ | PROT_WRITE, MAP_SHARED, fichier, 0);
	if (projection == (char *) MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	close(fichier);

	strncpy(cle, argv[2], 8);
	des_setparity(cle);

	retour = ecb_crypt(cle, projection, taille_fichier, mode);
	if (DES_FAILED(retour)) {
		perror("ecb_crypt");
		exit(EXIT_FAILURE);
	}
	munmap(projection, taille_fichier);
	return EXIT_SUCCESS;
}

