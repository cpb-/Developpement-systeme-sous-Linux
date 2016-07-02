// ------------------------------------------------------------------
// exemple-uname.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main (void)
{
	struct utsname	utsname;
	uname(& utsname);
	fprintf(stdout, " sysname  = %s \n nodename = %s \n"
	        " release  = %s \n version  = %s \n"
	        " machine  = %s  \n domain   = %s \n",
	        utsname.sysname,
	        utsname.nodename,
	        utsname.release,
	        utsname.version,
	        utsname.machine,
	        utsname.domainname);
	return EXIT_SUCCESS;
}
