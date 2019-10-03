// ------------------------------------------------------------------
// exemple-write.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
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

#define BLOCK_SIZE    1024
#define OVERRUN       767


void signal_handler(int number)
{
	fprintf(stderr, "Signal %d recu : %s\n", number, strsignal(number));
}

int main (void)
{
	struct rlimit limit;
	int  fd;
	char block[BLOCK_SIZE];
	int  written;

	signal(SIGXFSZ, signal_handler);

	if (getrlimit(RLIMIT_FSIZE, & limit) != 0) {
		perror("getrlimit");
		exit(EXIT_FAILURE);
	}
	limit.rlim_cur = 3 * BLOCK_SIZE + OVERRUN;
	if (setrlimit(RLIMIT_FSIZE, & limit) != 0) {
		perror("setrlimit");
		exit(EXIT_FAILURE);
	}
	fd = open("essai.write", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	memset(block, 1, BLOCK_SIZE);
	do {
		written = write(fd, block, BLOCK_SIZE);
		if (written != BLOCK_SIZE) {
			fprintf(stderr, "written = %d\n", written);
			if (errno != 0) {
				fprintf(stderr, "errno = %d : ", errno);
				perror("");
			}
		}
	} while (written != -1);
	close(fd);

	return EXIT_SUCCESS;
}

