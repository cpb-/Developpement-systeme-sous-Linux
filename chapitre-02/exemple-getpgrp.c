// ------------------------------------------------------------------
// exemple-getpgrp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char * argv[])
{
	fprintf(stdout, "%ld : %ld\n",
	        (long) getpid(), (long) getpgrp());
	return 0;
}
