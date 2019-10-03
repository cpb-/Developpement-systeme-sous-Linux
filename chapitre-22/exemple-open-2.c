// ------------------------------------------------------------------
// exemple-open-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (void)
{
	int	fd;

	if ((fd = open("essai.open", O_RDWR | O_CREAT | O_EXCL, 0777)) < 0)
		perror("open");
	else
		close(fd);

	return EXIT_SUCCESS;
}
