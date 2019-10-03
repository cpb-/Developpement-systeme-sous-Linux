// ------------------------------------------------------------------
// exemple-open.c
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

void open_file(char *name, char *type, int attribut, mode_t mode)
{
	int fd;

	fprintf(stderr, "%s (%s) : ", name, type);
	fd = open(name, attribut, mode);
	if (fd < 0) {
		perror("");
	} else {
		fprintf(stderr, "Ok\n");
		close(fd);
	}
}

int main (void)
{
	open_file("/etc/passwd", "O_RDONLY", O_RDONLY, 0);
	open_file("/etc/passwd", "O_RDWR", O_RDWR, 0);
	open_file("essai.open", "O_RDONLY", O_RDONLY, 0);
	open_file("essai.open", "O_RDWR", O_RDWR, 0);
	open_file("essai.open", "O_RDONLY | O_CREAT, 0640",
	                  O_RDONLY | O_CREAT, 
	                  S_IRUSR | S_IWUSR | S_IRGRP);
	open_file("essai.open", "O_RDWR | O_CREAT | O_EXCL, 0640", 
	                  O_RDWR | O_CREAT | O_EXCL, 
	                  S_IRUSR | S_IWUSR | S_IRGRP);

	return EXIT_SUCCESS;
}

