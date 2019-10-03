// ------------------------------------------------------------------
// exemple-putenv.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void find_var(char * name);

int main(void)
{
	fprintf(stdout, "\n--- test de putenv() ---\n");
	find_var("ESSAI");
	fprintf(stdout, "putenv(\"ESSAI=UN\");\n");
	putenv("ESSAI=UN");	
	find_var("ESSAI");
	fprintf(stdout, "putenv(\"ESSAI=\");\n");
	putenv("ESSAI=");
	find_var("ESSAI");
	fprintf(stdout, "putenv(\"ESSAI\"); equivaut a unsetenv()\n");
	putenv("ESSAI");
	find_var("ESSAI");
	
	fprintf(stdout, "\n--- test de setenv() ---\n");
	find_var("ESSAI");
	fprintf(stdout, "setenv(\"ESSAI\", \"DEUX\", 1);\n");
	setenv("ESSAI", "DEUX", 1);	
	find_var("ESSAI");
	fprintf(stdout, "setenv(\"ESSAI\", \"TROIS\", 1);\n");
	setenv("ESSAI", "TROIS", 1);
	find_var("ESSAI");
	fprintf(stdout, "setenv(\"ESSAI\", \"QUATRE\", 0);" 
                    "  ecrasement de valeur non autorise\n");
	setenv("ESSAI", "QUATRE", 0);
	find_var("ESSAI");

	fprintf(stdout, "\n-- test de unsetenv() --\n");
	find_var("ESSAI");
	fprintf(stdout, "unsetenv(\"ESSAI\");\n");
	unsetenv("ESSAI");	
	find_var("ESSAI");

	return 0;
}


void find_var (char * name)
{
	char * value;
	fprintf(stdout, "   var %s ", name);
	value = getenv(name);
	if (value == NULL)
		fprintf(stdout, "doesn't exist\n");
	else
		fprintf(stdout, "= %s\n", value);
}

