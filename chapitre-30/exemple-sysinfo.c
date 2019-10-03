// ------------------------------------------------------------------
// exemple-sysinfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <linux/kernel.h>

int main (void)
{
	struct sysinfo info;

	if (sysinfo(& info) != 0) {
		perror("sysinfo");
		exit(1);
	}
	fprintf(stdout, "Nb secondes depuis boot    : %ld \n",
	        info.uptime);
	fprintf(stdout, "Charge systeme depuis 1 mn : %.2f%%\n",
	        info.loads[0] / 655.36);
	fprintf(stdout, "                      5 mn : %.2f%%\n",
	        info.loads[1] / 655.36);
	fprintf(stdout, "                     10 mn : %.2f%%\n",
	        info.loads[2] / 655.36);
	fprintf(stdout, "Memoire disponible         : %ld Mo\n",
	        info.freeram >> 20);
	fprintf(stdout, "Memoire partagee           : %ld Mo\n",
	        info.sharedram >> 20);
	fprintf(stdout, "Memoire dans buffers       : %ld Mo\n",
	        info.bufferram >> 20);
	fprintf(stdout, "Espace de swap total       : %ld Mo\n",
	        info.totalswap >> 20);
	fprintf(stdout, "Espace de swap libre       : %ld Mo\n",
	        info.freeswap  >> 20);
	fprintf(stdout, "Nb processus en cours      : %d  \n",
	        info.procs);

	return EXIT_SUCCESS;
}


