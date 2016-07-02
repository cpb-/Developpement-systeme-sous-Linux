// ------------------------------------------------------------------
// exemple-localeconv.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	struct lconv * lconv;
	setlocale(LC_ALL, "");
	lconv = localeconv();
	printf("decimal_point     = %s \n", lconv->decimal_point);
	printf("thousands_sep     = %s \n", lconv->thousands_sep);
	printf("mon_decimal_point = %s \n", lconv->mon_decimal_point);
	printf("mon_thousands_sep = %s \n", lconv->mon_thousands_sep);
	printf("currency_symbol   = %s \n", lconv->currency_symbol);
	printf("int_curr_symbol   = %s \n", lconv->int_curr_symbol);
	printf("positive_sign     = %s \n", lconv->positive_sign);
	printf("negative_sign     = %s \n", lconv->negative_sign);
	printf("frac_digits       = %d \n", lconv->frac_digits);
	printf("int_frac_digits   = %d \n", lconv->int_frac_digits);
	printf("p_cs_precedes     = %d \n", lconv->p_cs_precedes);
	printf("p_sep_by_space    = %d \n", lconv->p_sep_by_space);
	printf("p_sign_posn       = %d \n", lconv->p_sign_posn);
	printf("n_cs_precedes     = %d \n", lconv->n_cs_precedes);
	printf("n_sep_by_space    = %d \n", lconv->n_sep_by_space);
	printf("n_sign_posn       = %d \n", lconv->n_sign_posn);
	return EXIT_SUCCESS;
}

