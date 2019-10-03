// ------------------------------------------------------------------
// exemple-nl-langinfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <locale.h>
#include <langinfo.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int	i;
	char *  label[] = {
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
	nl_item item[] = {
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
	for (i = 0; label[i] != NULL; i ++)
		fprintf(stdout, "%10s = \"%s\"\n", label[i], nl_langinfo(item[i]));
	return EXIT_SUCCESS;
}
