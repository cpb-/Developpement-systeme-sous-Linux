// ------------------------------------------------------------------
// exemple-tsearch.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void *itm1, const void *itm2)
{
	return strcmp(itm1, itm2);
}

static VISIT  display_visit;

void display(const void *node, const VISIT visit, const int depth)
{
	if (visit == display_visit)
		fprintf(stdout, "%s ", * (char **)node);
	else if (visit == leaf)
		fprintf(stdout, "(%s) ", * (char **) node);
}

int main (void)
{
	int   i;
	void *root = NULL;
	char *strings [] = {
	"A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P",
	"Q", "S", "D", "F", "G", "H", "J", "K", "L", "M",
	"W", "X", "C", "V", "B", "N", NULL,
	};

	/* Insertion des chaines dans l'arbre binaire */
	for (i = 0; strings[i] != NULL; i ++)
		if (tsearch(strings[i], &root, compare_char) == NULL) {
			perror("tsearch");
			exit(EXIT_FAILURE);
		}

	for (i = 0; strings[i] != NULL; i ++)
		if (tfind(strings[i], &root, compare_char) == NULL) {
			fprintf(stderr, "%s missing ?\n", strings[i]);
			exit(EXIT_FAILURE);
	}

	fprintf(stdout, "Parcours preorder (+ leaf) : \n  ");
	display_visit = preorder;
	twalk(root, display);
	fprintf(stdout, "\n");

	fprintf(stdout, "Parcours postorder (+ leaf) : \n  ");
	display_visit = postorder;
	twalk(root, display);
	fprintf(stdout, "\n");

	fprintf(stdout, "Parcours endorder (+ leaf) : \n  ");
	display_visit = endorder;
	twalk(root, display);
	fprintf(stdout, "\n");

	fprintf(stdout, "Parcours leaf : \n  ");
	display_visit = leaf;
	twalk(root, display);
	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}

