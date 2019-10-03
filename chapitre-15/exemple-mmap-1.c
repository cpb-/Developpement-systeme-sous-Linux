// ------------------------------------------------------------------
// exemple-mmap-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main (int argc, char * argv[])
{
	int    i;
	int    fd;
	char   tmp;
	char  *mapping;
	long   file_size;
	struct stat file_stat;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s file_to_invert\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDWR)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, &file_stat) != 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	file_size = file_stat.st_size;
	mapping = (char *) mmap(NULL, file_size,
				PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (mapping == (char *) MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	close(fd);
	for (i = 0; i < file_size / 2; i ++) {
		tmp = mapping[i];
		mapping[i] = mapping[file_size - i - 1];
		mapping[file_size - i - 1] = tmp;
	}
	munmap((void *)mapping, file_size);
	return EXIT_SUCCESS;
}

