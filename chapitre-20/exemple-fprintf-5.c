// ------------------------------------------------------------------
// exemple-fprintf-5.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	int	i;
	time_t	timer;
	struct tm * date;
	char * format[2] =
	  { "La date est %3$02d/%2$02d/%1$02d\n",
	    "Today is %1$02d %2$02d %3$02d\n" };

	time(& timer);
	date = localtime(& timer);
	for (i = 0; i < 2; i ++)
		fprintf (stdout, format[i], 
				date->tm_year % 100,
				date->tm_mon + 1,
				date->tm_mday);
	return EXIT_SUCCESS;
}
