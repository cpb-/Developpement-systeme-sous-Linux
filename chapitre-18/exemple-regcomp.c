// ------------------------------------------------------------------
// exemple-regcomp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

void display_options (char * nom_prog)
{
	fprintf(stderr, "Syntaxe : %s [options] motif\n", nom_prog);
	fprintf(stderr, " Options :\n");
	fprintf(stderr, "  -e : expressions rationnelles etendues\n");
	fprintf(stderr, "  -i : pas de differences majuscule/minuscule\n");
	fprintf(stderr, "  -s : ne pas memoriser les sous-expressions\n");
	fprintf(stderr, "  -n : gerer les sauts de lignes\n");
	fprintf(stderr, "  -d : debut de chaine sans saut de ligne\n");
	fprintf(stderr, "  -f : fin de chaine sans saut de ligne\n");
}

	#define LG_MAXI	256

int main (int argc, char * argv[])
{
	int     option;

	int     opt_regcomp = 0;
	int     opt_regexec = 0;
	regex_t compiled_regex;

	int     err;
	char   *err_message;
	size_t  message_len;

	size_t  match_count = 0;
	regmatch_t *matches = NULL;	

	char    line[LG_MAXI];
	char    substring[LG_MAXI];
	size_t  substring_len;
	int     i;

	opterr = 0; // pas de message d'erreur de getopt()
	while ((option = getopt(argc, argv, "eisndf")) != -1 ){
		switch (option) {
			case 'e' :
				opt_regcomp |= REG_EXTENDED;
				break;
			case 'i' :
				opt_regcomp |= REG_ICASE;
				break;
			case 's' :
				opt_regcomp |= REG_NOSUB;
				break;
			case 'n' :
				opt_regcomp |= REG_NEWLINE;
				break;
			case 'd' :
				opt_regexec |= REG_NOTBOL;
				break;
			case 'f' :
				opt_regexec |= REG_NOTEOL;
				break;
			case '?' :
				display_options(argv [0]);
				exit (1);
		}
	}
	if (argc - optind != 1) {
		// il manque le motif
		display_options(argv[0]);
		exit(EXIT_FAILURE);
	}

	err = regcomp(&compiled_regex, argv[argc - 1], opt_regcomp);
	if (err != 0) {
		message_len = regerror(err, &compiled_regex, NULL, 0);
		err_message = malloc(message_len);
		if (err_message == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		regerror(err, &compiled_regex, err_message, message_len);
		fprintf(stderr, "%s\n", err_message);
		free(err_message);
		exit(EXIT_FAILURE);
	}

	if ((opt_regcomp & REG_NOSUB) == 0) {
		match_count = compiled_regex.re_nsub + 1;
		matches = calloc(match_count, sizeof (regmatch_t));
		if (matches == NULL) {
			perror("calloc");
			exit(EXIT_FAILURE);
		}
	}

	while (fgets(line, LG_MAXI, stdin) != NULL) {

		err = regexec(&compiled_regex, line, match_count,
				matches, opt_regexec);
		if (err == REG_NOMATCH) {
			fprintf(stdout, "Pas de correspondance\n");
			continue;
		}
		if (err == REG_ESPACE) {
			fprintf(stderr, "Pas assez de memoire\n");
			exit(EXIT_FAILURE);
		}

		fprintf(stdout, "Correspondance Ok\n");

		if ((opt_regcomp & REG_NOSUB) != 0)
			continue;

		for (i = 0; i < match_count; i ++) {
			substring_len = matches[i].rm_eo - matches[i].rm_so;
			strncpy (substring, line + matches[i].rm_so, substring_len);
			substring[substring_len] = '\0';
			if (i == 0) 
				fprintf (stdout, "expression : %s\n", substring);
			else
				fprintf (stdout, "ss-expr %02d : %s\n", i, substring);
		}
	}

	// Ces liberations seraient indispensables si l'on voulait
	// compiler un nouveau motif
	free(matches);
	matches = NULL;
	match_count = 0;
	regfree(&compiled_regex);

	return EXIT_SUCCESS;
}

