// ------------------------------------------------------------------
// exemple-readlink.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void read_content(const char *name)
{
	char *buffer = NULL;
	char *reallocated_buffer = NULL;
	int	size = 0;
	int	written;

	while (1) {
		size += 16;
		if ((reallocated_buffer = realloc(buffer, size)) == NULL) {
			perror(name);
			break;
		}
		buffer = reallocated_buffer;
		if ((written = readlink(name, buffer, size - 1)) == -1) {
			perror(name);
			break;
		}
		if (written < size - 1) {
			buffer[written] = '\0';
			fprintf(stdout, "%s : %s\n", name, buffer);
			break;
		}
	}
	free(buffer);
}


int main (int argc, char * argv[])
{
	int i;

	for (i = 1; i < argc; i ++)
		read_content(argv[i]);

	return EXIT_SUCCESS;
}

