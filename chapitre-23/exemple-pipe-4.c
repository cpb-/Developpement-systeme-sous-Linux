// ------------------------------------------------------------------
// exemple-pipe-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int execute_command(const char *command, int fd[2])
{
	int	pipe_1[2];
	int	pipe_2[2];

	if ((pipe(pipe_1) != 0) || (pipe(pipe_2) != 0))
		return -1;
	switch (fork()) {
		case -1 :
			close(pipe_1[0]); close(pipe_1[1]);
			close(pipe_2[0]); close(pipe_2[1]);
			return -1;
		case 0 : 
			close(pipe_1[1]);
			close(pipe_2[0]);
			dup2(pipe_1[0], STDIN_FILENO);
			dup2(pipe_2[1], STDOUT_FILENO);
			system(command);
			exit(EXIT_SUCCESS);
		default :
			close(pipe_1[0]);
			close(pipe_2[1]);
			fd[0] = pipe_2[0];
			fd[1] = pipe_1[1];
	}

	return 0;
}

int main (int argc, char * argv[])
{
	int    pipe_fd[2];
	FILE  *fp;
	char  *content;
	struct stat status;
	char   c;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s fichier\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (stat(argv[1], &status) != 0) {
		perror("stat");
		exit(EXIT_FAILURE);
	}
	if ((content = malloc(status.st_size)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	if (fread(content, 1, status.st_size, fp) != status . st_size) {
		perror("fread");
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	if (execute_command("wc -w", pipe_fd) != 0) {
		perror("execute_command");
		exit(EXIT_FAILURE);
	}
	write(pipe_fd[1], content, status.st_size);
	close(pipe_fd[1]);

	fprintf(stdout, "Nombre de mots :   ");
	while (read(pipe_fd[0], &c, 1) == 1)
		fputc(c, stdout);
	close(pipe_fd[0]);

	if (execute_command("wc -l", pipe_fd) != 0) {
		perror("execute_command");
		exit(EXIT_FAILURE);
	}
	write(pipe_fd[1], content, status.st_size);
	close(pipe_fd[1]);

	fprintf(stdout, "Nombre de lignes : ");
	while (read(pipe_fd[0], &c, 1) == 1)
		fputc(c, stdout);
	close(pipe_fd[0]);

	free(content);
	return EXIT_SUCCESS;
}

