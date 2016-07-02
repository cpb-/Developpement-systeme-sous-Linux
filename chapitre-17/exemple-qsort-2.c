// ------------------------------------------------------------------
// exemple-qsort-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * b_insert (const void * cle, const void * table, 
	  size_t * nb_elements, size_t taille_element, 
	int (* compare) (const void * lm1, const void * lm2))
{
	const char * element;
	int          comparaison;

	size_t bas  = 0;
	size_t haut = (* nb_elements);
	size_t milieu;

	while (bas < haut) {

		milieu = bas + (haut - bas) / 2;
		element = (void *) (((const char *) table)
		        + (milieu * taille_element));
		comparaison = compare(cle, element);
		if (comparaison < 0)
			haut = milieu;
		else if (comparaison > 0)
			bas = milieu + 1;
		else
			return ((void *) element);
	}
	// Ici, haut = bas, on n'a pas trouve l'element, on va l'ajouter,
  	//  mais nous devons verifier de quel cote de l'element "haut".
	if (haut >= (* nb_elements)) {
		element = (void *) (((const char *) table)
	        	+ ((* nb_elements) * taille_element));
	} else {
		
		element = (void *) (((const char *) table)
		        + (haut * taille_element));
		if (compare(cle, element) > 0) {
			element += taille_element;
			haut ++;
		}
		memmove((char *) element + taille_element, (char *) element, (* nb_elements) - haut);
	}
	memcpy((void *) element, cle, taille_element);
	(* nb_elements) ++;
	return (void *) element;
}

int compare_char (const void * lm1, const void * lm2)
{
	return  ((char *)lm1)[0] - ((char *)lm2)[0];
}

int main (int argc, char * argv[])
{
	char *	table = NULL;
	size_t	longueur;

	if (argc != 3) {
		fprintf(stderr, "syntaxe: %s table element\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	longueur = strlen(argv[1]);
	if ((table = malloc(longueur + 2)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(table, argv[1]);

	fprintf(stdout, "tri avec qsort ...\n");
	qsort(table, strlen(table), 1, compare_char);
	fprintf(stdout, "%s\n", table);

	fprintf(stdout, "recherche / insertion de %c\n", argv[2][0]);
	b_insert((void *) argv[2], table, & longueur, 1, compare_char);
	table[longueur] = '\0';
	fprintf(stdout, "%s\n", table);

	return EXIT_SUCCESS;
}
