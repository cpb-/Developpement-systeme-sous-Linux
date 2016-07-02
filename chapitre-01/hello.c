	#include <stdio.h>

int main (int argc, char * argv [])
{
	int i;
	fprintf (stdout, "Hello world ! ");
	if (argc > 1)
	{
		fprintf (stdout, ": ");
		/* Parcours et affichage des arguments */
		for (i = 1; i < argc; i ++) fprintf (stdout, "%s ", argv [i]);
	}
	fprintf (stdout, "\n");
	return (0);
}

