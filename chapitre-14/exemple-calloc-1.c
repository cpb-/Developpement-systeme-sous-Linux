// ------------------------------------------------------------------
// exemple-calloc-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int *compute_fibonacci(int value_count)
{
	int *table = NULL;
	int	i;

	if ((table = calloc(value_count, sizeof(int))) == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	if (value_count > 0) {
		table[0] = 1;
		if (value_count > 1) {
			table[1] = 1;
			for (i = 2; i < value_count; i ++)
				table[i] = table[i - 2] + table[i - 1];
		}
	}
	return table;
}


int main (int argc, char * argv[])
{
	int	value_count;
	int *table;
	int	i;

	if ((argc != 2) || (sscanf(argv[1], "%d", &value_count) != 1)) {
		fprintf(stderr, "Usage: %s value_count\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	table = compute_fibonacci(value_count);
	for (i = 0; i < value_count; i ++)
		fprintf(stdout, "%d\n", table[i]);
	free(table);
	return EXIT_SUCCESS;
}

