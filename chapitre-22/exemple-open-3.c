// ------------------------------------------------------------------
// exemple-open-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


FILE * exclusive_fopen(const char *name, const char *mode)
{
	int	can_read = 0;
	int	can_write = 0;
	int	append = 0;
	int	creation = 0;
	int	troncate = 0;
	int	flags = 0;
	int	i;
	int	fd;
	FILE *	fp;

	for (i = 0; i < strlen(mode); i ++) {
		switch (mode[i]) {
			case 'a' :
				can_write = can_read = append = 1;
				break;
			case 'r' :
				can_read = 1;
				break;
			case 'w' :
				can_write = creation = troncate = 1;
				break;
			case '+' :
				can_write = can_read = 1;
				break;
			default :
				// soyons tolerants... on ne dit rien
				break;
		}
	}
	if (can_read & can_write)
		flags = O_RDWR;
	else if (can_read)
		flags = O_RDONLY;
	else if (can_write)
		flags = O_WRONLY;
	else {
		errno = EINVAL;
		return (NULL);
	}
	if (creation)
		flags |= O_CREAT;
	if (troncate)
		flags |= O_TRUNC;
	flags |= O_EXCL;
	fd = open(name, flags, 0644);
	if (fd < 0)
		return NULL;
	fp = fdopen(fd, mode);

	return fp;
}


void open_file(const char *name, const char *mode, int exclusif)
{
	FILE * fp;

	fprintf(stderr, "Ouverture %sde %s, mode %s : ", 
		(exclusif ? "exclusive " : ""), name, mode);
	if (exclusif)
		fp = exclusive_fopen(name, mode);
	else
		fp = fopen(name, mode);
	if (fp == NULL)
		perror("");
	else {
		fprintf(stderr, "Ok\n");
		fclose(fp);
	}
}

int main (void)
{
	open_file("essai.open_3", "w+", 1);
	open_file("essai.open_3", "w+", 1);
	open_file("essai.open_3", "w+", 0);

	return EXIT_SUCCESS;
}
