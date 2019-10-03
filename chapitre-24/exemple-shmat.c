// ------------------------------------------------------------------
// exemple-shmat.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>

typedef union semun {
	int                  value;
	struct   semid_ds *  buffer;
	unsigned short int * table;
} semun_t;	

int main (int argc, char * argv[])
{
	key_t         key;
	int           sem;
	int           shm;
	struct sembuf sembuf;
	semun_t       u_semun;
	int *         counter = NULL;
	unsigned short table[1] = {1};
	
	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s fichier_cle \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((key = ftok(argv[1], 0)) == -1) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	if ((shm = shmget(key, sizeof(int), IPC_CREAT | 0600)) == -1) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	if ((counter = shmat(shm, NULL, 0)) == (void *)-1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	if ((sem = semget(key, 1, 0)) == -1) {
		if ((sem = semget(key, 1, IPC_CREAT | IPC_EXCL | 0600)) == -1) {
			perror("semget");
			exit(EXIT_FAILURE);
		}
		u_semun.table = table;
		if (semctl(sem, 0, SETALL, u_semun) < 0)
			perror("semctl");
	}
	sembuf.sem_num = 0;
	sembuf.sem_flg = SEM_UNDO;
	while (1) {
		// P() 	
		sembuf.sem_op = -1;
		if (semop(sem, &sembuf, 1) < 0) {
			perror("semop");
			exit(EXIT_FAILURE);
		}
		// Incrementation du counter
		(* counter) ++;
		fprintf(stdout, "%d\n", *counter);
		// V()
		sembuf.sem_op = 1;
		if (semop(sem, &sembuf, 1) < 0) {
			perror("semop");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}

	return EXIT_SUCCESS;
}

