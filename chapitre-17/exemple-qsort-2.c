// ------------------------------------------------------------------
// exemple-qsort-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * b_insert(const void *key, const void * table, 
                size_t *nb_items, size_t item_size, 
                int (* compare)(const void *, const void *))
{
	const char *item;
	int comparison;

	size_t bottom  = 0;
	size_t top = (* nb_items);
	size_t middle;

	while (bottom < top) {

		middle = bottom + (top - bottom) / 2;
		item = (void *) (((const char *) table)
		        + (middle * item_size));
		comparison = compare(key, item);
		if (comparison < 0)
			top = middle;
		else if (comparison > 0)
			bottom = middle + 1;
		else
			return ((void *) item);
	}
	// Ici, top = bottom, on n'a pas trouve l'element, on va l'ajouter,
	//  mais nous devons verifier de quel cote de l'element "top".
	if (top >= (*nb_items)) {
		item = (void *) (((const char *)table)
		      + ((* nb_items) * item_size));
	} else {
		
		item = (void *) (((const char *) table)
		        + (top * item_size));
		if (compare(key, item) > 0) {
			item += item_size;
			top ++;
		}
		memmove((char *)item + item_size, (char *)item, (*nb_items) - top);
	}
	memcpy((void *)item, key, item_size);
	(*nb_items) ++;
	return (void *)item;
}

int compare_char (const void *itm1, const void *itm2)
{
	return  ((char *)itm1)[0] - ((char *)itm2)[0];
}

int main (int argc, char * argv[])
{
	char *	table = NULL;
	size_t	size;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s table item\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	size = strlen(argv[1]);
	if ((table = malloc(size + 2)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(table, argv[1]);

	fprintf(stdout, "tri avec qsort ...\n");
	qsort(table, strlen(table), 1, compare_char);
	fprintf(stdout, "%s\n", table);

	fprintf(stdout, "recherche / insertion de %c\n", argv[2][0]);
	b_insert((void *) argv[2], table, &size, 1, compare_char);
	table[size] = '\0';
	fprintf(stdout, "%s\n", table);

	return EXIT_SUCCESS;
}
