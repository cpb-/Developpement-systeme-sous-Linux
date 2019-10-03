// ------------------------------------------------------------------
// exemple-hsearch-r.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define	_GNU_SOURCE
#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_entry(char *name, long number, struct hsearch_data *table)
{
	ENTRY  entry;
	ENTRY *result;

	entry.key  = strdup(name);
	entry.data = (char *)number;
	if (hsearch_r(entry, ENTER, &result, table) == 0) {
		perror("hsearch_r");
		exit(EXIT_FAILURE);
	}
}


int main(int argc, char * argv[])
{
	struct  hsearch_data table;
	int     i;
	ENTRY   entry;
	ENTRY  *found;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s nom-dept\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	memset(&table, 0, sizeof(table));
	if (hcreate_r(100, &table) == 0) { 
		perror("hcreate");
		exit(EXIT_FAILURE);
	}

	add_entry("ain",                     1, & table);
	add_entry("aisne",                   2, & table);
	add_entry("allier",                  3, & table);
	add_entry("alpes-de-haute-provence", 4, & table);
	add_entry("hautes-alpes",            5, & table);
	add_entry("alpes-maritimes",         6, & table);
	add_entry("ardeche",                 7, & table);
	add_entry("ardennes",                8, & table);
	add_entry("ariege",                  9, & table);
	add_entry("aube",                   10, & table);
	add_entry("aude",                   11, & table);
	add_entry("aveyron",                12, & table);
	add_entry("bouches-du-rhone",       13, & table);
	add_entry("calvados",               14, & table);
	add_entry("cantal",                 15, & table);
	add_entry("charente",               16, & table);
	add_entry("charente-maritime",      17, & table);
	add_entry("cher",                   18, & table);
	add_entry("correze",                19, & table);
	add_entry("corse",                  20, & table);
	add_entry("cote-d'or",              21, & table);
	add_entry("cotes-d'armor",          22, & table);
	add_entry("creuse",                 23, & table);
	add_entry("dordogne",               24, & table);
	add_entry("doubs",                  25, & table);
	add_entry("drome",                  26, & table);
	add_entry("eure",                   27, & table);
	add_entry("eure-et-loir",           28, & table);
	add_entry("finistere",              29, & table);
	add_entry("gard",                   30, & table);
	add_entry("haute-garonne",          31, & table);
	add_entry("gers",                   32, & table);
	add_entry("gironde",                33, & table);
	add_entry("herault",                34, & table);
	add_entry("ille-et-vilaine",        35, & table);
	add_entry("indre",                  36, & table);
	add_entry("indre-et-loire",         37, & table);
	add_entry("isere",                  38, & table);
	add_entry("jura",                   39, & table);
	add_entry("landes",                 40, & table);
	add_entry("loir-et-cher",           41, & table);
	add_entry("loire",                  42, & table);
	add_entry("haute-loire",            43, & table);
	add_entry("loire-atlantique",       44, & table);
	add_entry("loiret",                 45, & table);
	add_entry("lot",                    46, & table);
	add_entry("lot-et-garonne",         47, & table);
	add_entry("lozere",                 48, & table);
	add_entry("maine-et-loire",         49, & table);
	add_entry("manche",                 50, & table);
	add_entry("marne",                  51, & table);
	add_entry("haute-marne",            52, & table);
	add_entry("mayenne",                53, & table);
	add_entry("meurthe-et-moselle",     54, & table);
	add_entry("meuse",                  55, & table);
	add_entry("morbihan",               56, & table);
	add_entry("moselle",                57, & table);
	add_entry("nievre",                 58, & table);
	add_entry("nord",                   59, & table);
	add_entry("oise",                   60, & table);
	add_entry("orne",                   61, & table);
	add_entry("pas-de-calais",          62, & table);
	add_entry("puy-de-dome",            63, & table);
	add_entry("pyrenees-atlantique",    64, & table);
	add_entry("haute-pyrenees",         65, & table);
	add_entry("pyrenees-orientale",     66, & table);
	add_entry("bas-rhin",               67, & table);
	add_entry("haut-rhin",              68, & table);
	add_entry("rhone",                  69, & table);
	add_entry("haute-saone",            70, & table);
	add_entry("saone-et-loire",         71, & table);
	add_entry("sarthe",                 72, & table);
	add_entry("savoie",                 73, & table);
	add_entry("haute-savoie",           74, & table);
	add_entry("paris",                  75, & table);
	add_entry("seine-maritime",         76, & table);
	add_entry("seine-et-marne",         77, & table);
	add_entry("yvelines",               78, & table);
	add_entry("deux-sevres",            79, & table);
	add_entry("somme",                  80, & table);
	add_entry("tarn",                   81, & table);
	add_entry("tarn-et-garonne",        82, & table);
	add_entry("var",                    83, & table);
	add_entry("vaucluse",               84, & table);
	add_entry("vendee",                 85, & table);
	add_entry("vienne",                 86, & table);
	add_entry("haute-vienne",           87, & table);
	add_entry("vosges",                 88, & table);
	add_entry("yonne",                  89, & table);
	add_entry("territoire-de-belfort",  90, & table);
	add_entry("essonne",                91, & table);
	add_entry("hauts-de-seine",         92, & table);
	add_entry("seine-saint-denis",      93, & table);
	add_entry("val-de-marne",           94, & table);
	add_entry("val-d'oise",             95, & table);

	for (i = 1; i < argc; i ++) {
		entry.key = argv[i];
		fprintf(stdout, "%s -> ", argv[i]);
		if (hsearch_r(entry, FIND, &found, &table) == 0)
			fprintf(stdout, "pas dans la liste \n");
		else
			fprintf(stdout, "%ld\n", (long) (found->data));
	}
	hdestroy_r(&table);
	return EXIT_SUCCESS;
}

