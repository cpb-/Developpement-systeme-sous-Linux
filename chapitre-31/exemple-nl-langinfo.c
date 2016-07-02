// ------------------------------------------------------------------
// exemple-nl-langinfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <langinfo.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int	i;
	char *  libelles[] = {
		"YESEXPR", "NOEXPR",
		"ABDAY_1", "ABDAY_7",
		"ABMON_1", "ABMON_12",
		"DAY_1",   "DAY_7",
		"MON_1",   "MON_12",
		"AM_STR",  "PM_STR",
		"D_FMT",   "D_T_FMT",
		"T_FMT",   "T_FMT_AMPM",
		NULL
	};
	nl_item objet[] = {
		YESEXPR, NOEXPR,
		ABDAY_1, ABDAY_7,
		ABMON_1, ABMON_12,
		DAY_1,   DAY_7,
		MON_1,   MON_12,
		AM_STR,  PM_STR,
		D_FMT,   D_T_FMT,
		T_FMT,   T_FMT_AMPM,
		0
	};
	setlocale(LC_ALL, "");
	for (i = 0; libelles[i] != NULL; i ++)
		fprintf(stdout, "%10s = \"%s\"\n", libelles[i], nl_langinfo(objet [i]));
	return EXIT_SUCCESS;
}
