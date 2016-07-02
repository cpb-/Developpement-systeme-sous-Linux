// ------------------------------------------------------------------
// exemple-putenv.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void	recherche_variable (char * nom);

int main (void)
{
	fprintf(stdout, "\n--- test de putenv() ---\n");
	recherche_variable("ESSAI");
	fprintf(stdout, "putenv(\"ESSAI=UN\");\n");
	putenv("ESSAI=UN");	
	recherche_variable("ESSAI");
	fprintf(stdout, "putenv(\"ESSAI=\");\n");
	putenv("ESSAI=");
	recherche_variable("ESSAI");
	fprintf(stdout, "putenv(\"ESSAI\"); equivaut a unsetenv()\n");
	putenv("ESSAI");
	recherche_variable("ESSAI");
	
	fprintf(stdout, "\n--- test de setenv() ---\n");
	recherche_variable("ESSAI");
	fprintf(stdout, "setenv(\"ESSAI\", \"DEUX\", 1);\n");
	setenv("ESSAI", "DEUX", 1);	
	recherche_variable("ESSAI");
	fprintf(stdout, "setenv(\"ESSAI\", \"TROIS\", 1);\n");
	setenv("ESSAI", "TROIS", 1);
	recherche_variable("ESSAI");
	fprintf(stdout, "setenv(\"ESSAI\", \"QUATRE\", 0);" 
                    "  ecrasement de valeur non autorise\n");
	setenv("ESSAI", "QUATRE", 0);
	recherche_variable("ESSAI");

	fprintf(stdout, "\n-- test de unsetenv() --\n");
	recherche_variable("ESSAI");
	fprintf(stdout, "unsetenv(\"ESSAI\");\n");
	unsetenv("ESSAI");	
	recherche_variable("ESSAI");

	return 0;
}

void recherche_variable (char * nom)
{
	char * valeur;
	fprintf(stdout, "   variable %s ", nom);
	valeur = getenv(nom);
	if (valeur == NULL)
		fprintf(stdout, "inexistante\n");
	else
		fprintf(stdout, "= %s\n", valeur);
}
