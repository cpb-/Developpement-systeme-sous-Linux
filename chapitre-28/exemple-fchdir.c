// ------------------------------------------------------------------
// exemple-fchdir.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void display_current_path(void)
{
	char *path = NULL;
	char *reallocated = NULL;
	int   size = 16;

	while (1) {	
		if ((reallocated = realloc(path, size)) == NULL) {
			perror("realloc");
			break;
		}
		path = reallocated;
		if (getcwd(path, size) != NULL) {
			fprintf(stdout, "%s\n", path);
			break;
		}
		if (errno != ERANGE) {
			perror("getcwd");
			break;
		}
		size *= 2;
	}
	if (path != NULL)
		free(path);
}

void change_directory(const char * name)
{
	int  fd;
	if ((fd = open(name, O_RDONLY)) < 0) {
		perror(name);
		return ;
	}
	if (fchdir(fd) < 0)
		perror(name);
	close(fd);
}

int main (int argc, char * argv[])
{
	int i;
	
	display_current_path();
	for (i = 1; i < argc; i++) {
		change_directory(argv[i]);
		display_current_path();
	}
	return EXIT_SUCCESS;
}
