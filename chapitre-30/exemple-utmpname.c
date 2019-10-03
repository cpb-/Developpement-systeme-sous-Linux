// ------------------------------------------------------------------
// exemple-utmpname.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>

void display_utmp(struct utmp * utmp)
{
	time_t     t;
	struct tm *tm;
	char       hour[80];

	t = utmp->ut_tv.tv_sec;
	tm = localtime(&t);
	strftime(hour, 80, "%x %X", tm);
	switch (utmp->ut_type) {
		case EMPTY :
			break;
		case RUN_LVL :
			printf("%s : ", hour);
			printf("Run-level \n");
			break;
		case BOOT_TIME :
			printf("%s : ", hour);
			printf("Boot \n");
			break;
		case OLD_TIME :
			printf("%s : ", hour);
			printf("Old Time\n");
			break;
		case NEW_TIME :
			printf("%s : ", hour);
			printf("New Time\n");
			break;
		case INIT_PROCESS :
			printf("%s : ", hour);
			printf("Init process, ");
			printf("PID = %u, ", utmp->ut_pid);
			printf("inittab = %s\n", utmp->ut_id);
			break;
		case LOGIN_PROCESS :
			printf("%s : ", hour);
			printf("Login process, ");
			printf("PID = %u, ", utmp->ut_pid);
			printf("TTY = %s\n", utmp->ut_line);
			break;
		case USER_PROCESS :
			printf("%s : ", hour);
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



int main (int argc, char * argv[])
{
	struct utmp * utmp;
	int	i;

	for (i = 1; i < argc; i ++) {
		if (utmpname(argv[1]) != 0)
			continue;
		while ((utmp = getutent()) != NULL)
			display_utmp(utmp);
	}

	return EXIT_SUCCESS;
}
