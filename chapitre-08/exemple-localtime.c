// ------------------------------------------------------------------
// exemple-localtime.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	time_t      now;
	struct tm * tm;

	time(&now);
//	now += 180 * 86400;
	fprintf(stdout, "time() = %ld \n", now);
	tm = localtime(&now);
	fprintf(stdout, "localtime() = %02d/%02d/%02d - %02d:%02d:%02d %s\n",
		tm->tm_mday, tm->tm_mon + 1, tm->tm_year % 100,
		tm->tm_hour, tm->tm_min, tm->tm_sec,
		tm->tm_isdst>0 ? "Été" : tm->tm_isdst==0 ? "Normal" : "?");
		tm = gmtime (&now);
	fprintf(stdout, "gmtime()    = %02d/%02d/%02d - %02d:%02d:%02d %s\n",
		tm->tm_mday, tm->tm_mon + 1, tm->tm_year % 100,
		tm->tm_hour, tm->tm_min, tm->tm_sec,
		tm->tm_isdst>0 ? "Été" : tm->tm_isdst==0 ? "Normal" : "?");

	return EXIT_SUCCESS;
}
