// ------------------------------------------------------------------
// exemple-getutent.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>

void affiche_utmp (struct utmp * utmp)
{
	struct tm * tm;
	char        heure[80];

	tm = localtime(& (utmp->ut_tv.tv_sec));
	strftime(heure, 80, "%x %X", tm);
	switch (utmp->ut_type) {
		case EMPTY :
			break;
		case RUN_LVL :
			printf("%s : ", heure);
			printf("Run-level \n");
			break;
		case BOOT_TIME :
			printf("%s : ", heure);
			printf("Boot \n");
			break;
		case OLD_TIME :
			printf("%s : ", heure);
			printf("Old Time\n");
			break;
		case NEW_TIME :
			printf("%s : ", heure);
			printf("New Time\n");
			break;
		case INIT_PROCESS :
			printf("%s : ", heure);
			printf("Init process, ");
			printf("PID = %u, ", utmp->ut_pid);
			printf("inittab = %s\n", utmp->ut_id);
			break;
		case LOGIN_PROCESS :
			printf("%s : ", heure);
			printf("Login process, ");
			printf("PID = %u, ", utmp->ut_pid);
			printf("TTY = %s\n", utmp->ut_line);
			break;
		case USER_PROCESS :
			printf("%s : ", heure);
			printf("User process, ");
			printf("PID = %u, ", utmp->ut_pid);
			printf("TTY = %s, ", utmp->ut_line);
			printf("%s \n", utmp->ut_user);
			break;
		case DEAD_PROCESS :
			break;
		default :
			printf("?");
			break;
	}
}

int main (void)
{
	struct utmp * utmp;
	while ((utmp = getutent()) != NULL)
		affiche_utmp(utmp);
	return EXIT_SUCCESS;
}
