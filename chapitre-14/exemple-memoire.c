// ------------------------------------------------------------------
// exemple-memoire.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main (int argc, char * argv [])
{
	int	i;
	int	block_count;
	int	block_size;
	char command_line[80];
	char **table = NULL;

	if ((argc != 3) 
	 || (sscanf(argv[1], "%d", &block_count) != 1)
	 || (sscanf(argv[2], "%d", &block_size) != 1)) {
		fprintf(stderr, "Usage: %s block_count block_size\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((block_count < 1) || (block_size < 1)) {
		fprintf(stderr, "Invalid values\n");
		exit(EXIT_FAILURE);
	}

	sprintf(command_line, "ps un %ld", (long) getpid());

	fprintf(stdout, "Je demarre...\n");
	system(command_line);

	fprintf(stdout, "J'alloue %d blocs de %d octets...", block_count, block_size);
	fflush(stdout);
	
	table = calloc(block_count, sizeof (char *));
	if (table == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < block_count; i ++) {
		table[i] = malloc(block_size);
		if (table[i] == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		memset(table[i], 1, block_size);
	}
	fprintf(stdout, "Ok\n");
	system(command_line);

	fprintf(stdout, "Je libere tous les blocs sauf le dernier\n");
	for (i = 0; i < block_count - 1; i ++)
		free(table[i]);
	system(command_line);

	fprintf(stdout, "Je libere le dernier bloc..\n");
	free(table[block_count - 1]);
	system(command_line);

	return EXIT_SUCCESS;
}
