// ------------------------------------------------------------------
// exemple-strerror.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main (void)
{
	fprintf(stdout, "strerror(EACCES) = %s\n", strerror(EACCES));
	fprintf(stdout, "strerror(EAGAIN) = %s\n", strerror(EAGAIN));
	fprintf(stdout, "strerror(EBUSY)  = %s\n", strerror(EBUSY) );
	fprintf(stdout, "strerror(ECHILD) = %s\n", strerror(ECHILD));
	fprintf(stdout, "strerror(EEXIST) = %s\n", strerror(EEXIST));
	fprintf(stdout, "strerror(EFAULT) = %s\n", strerror(EFAULT));
	fprintf(stdout, "strerror(EINTR)  = %s\n", strerror(EINTR) );
	fprintf(stdout, "strerror(EINVAL) = %s\n", strerror(EINVAL));
	fprintf(stdout, "strerror(EISDIR) = %s\n", strerror(EISDIR));
	fprintf(stdout, "strerror(EMFILE) = %s\n", strerror(EMFILE));
	fprintf(stdout, "strerror(ENODEV) = %s\n", strerror(ENODEV));
	fprintf(stdout, "strerror(ENOMEM) = %s\n", strerror(ENOMEM));
	fprintf(stdout, "strerror(ENOSPC) = %s\n", strerror(ENOSPC));
	fprintf(stdout, "strerror(EPERM)  = %s\n", strerror(EPERM) );
	fprintf(stdout, "strerror(EPIPE)  = %s\n", strerror(EPIPE) );
	fprintf(stdout, "strerror(ESRCH)  = %s\n", strerror(ESRCH) );
	
	return EXIT_SUCCESS;
}
