// ------------------------------------------------------------------
// exemple-dup.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int fd;
	fd = open("essai.dup", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	close(STDOUT_FILENO);
	if (dup (fd) < 0) {
		perror("dup");
		exit(EXIT_FAILURE);
	}
	close(fd);
	execlp("ls", "ls", NULL);
	perror("execlp");
	exit(EXIT_FAILURE);
}

