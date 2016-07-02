// ------------------------------------------------------------------
// exemple-open-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


FILE * fopen_exclusif (const char * nom_fichier, const char * mode_flux)
{
	int	lecture		= 0;
	int	ecriture	= 0;
	int	ajout		= 0;
	int	creation	= 0;
	int	troncature	= 0;
	int	flags		= 0;
	int	i;
	int	fd;
	FILE *	fp;

	for (i = 0; i < strlen(mode_flux); i ++) {
		switch (mode_flux[i]) {
			case 'a' :
				ecriture = lecture = ajout = 1;
				break;
			case 'r' :
				lecture = 1;
				break;
			case 'w' :
				ecriture = creation = troncature = 1;
				break;
			case '+' :
				ecriture = lecture = 1;
				break;
			default :
				// soyons tolerants... on ne dit rien
				break;
		}
	}
	if (lecture & ecriture)
		flags = O_RDWR;
	else if (lecture)
		flags = O_RDONLY;
	else if (ecriture)
		flags = O_WRONLY;
	else {
		errno = EINVAL;
		return (NULL);
	}
	if (creation)
		flags |= O_CREAT;
	if (troncature)
		flags |= O_TRUNC;
	flags |= O_EXCL;
	fd = open(nom_fichier, flags, 0644);
	if (fd < 0)
		return NULL;
	fp = fdopen(fd, mode_flux);
	return fp;
}

void ouverture (const char * nom, const char * mode, int exclusif)
{
	FILE * fp;
	fprintf(stderr, "Ouverture %sde %s, mode %s : ", 
		(exclusif ? "exclusive " : ""), nom, mode);
	if (exclusif)
		fp = fopen_exclusif(nom, mode);
	else
		fp = fopen(nom, mode);
	if (fp == NULL)
		perror("");
	else {
		fprintf(stderr, "Ok\n");
		fclose(fp);
	}
}

int main (void)
{
	ouverture("essai.open_3", "w+", 1);
	ouverture("essai.open_3", "w+", 1);
	ouverture("essai.open_3", "w+", 0);
	return EXIT_SUCCESS;
}
