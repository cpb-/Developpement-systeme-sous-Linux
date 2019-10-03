// ------------------------------------------------------------------
// exemple-umask.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main (void)
{
	int	fd;
	int	mask;

	mask = umask(0);
	fprintf(stdout, "Ancien masque = %o, nouveau = 0 \n", mask);
	fprintf(stdout, "Tentative de creation de essai.umask \n");
	fd = open("essai.umask", O_RDWR | O_CREAT | O_EXCL, 0777);
	if (fd < 0)
		perror("open");
	else
		close(fd);
	system("ls -l essai.umask");
	unlink("essai.umask");

	umask(mask);
	fprintf(stdout, "Remise masque = %o \n", mask);
	fprintf(stdout, "Tentative de creation de essai.umask \n");
	fd = open("essai.umask", O_RDWR | O_CREAT | O_EXCL, 0777);
	if (fd < 0)
		perror("open");
	else
		close(fd);
	system("ls -l essai.umask");
	unlink("essai.umask");

	return EXIT_SUCCESS;
}	

