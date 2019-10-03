// ------------------------------------------------------------------
// stdin-2-serie.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define LG_BUFFER    1024

void setspeed(struct termios * config, speed_t speed)
{
	cfsetispeed(config, speed);
	cfsetospeed(config, speed);
}


int main (int argc, char * argv[])
{
	char *tty_name  = "/dev/ttyS0";
	int	speed  = 9600;
	int	parity = 'n';
	int	data_bits = 8;
	int	stop_bits = 1;
	int	tty_fd  = -1;
	struct termios config_termios;
	struct termios saved_termios;
	char   buffer[LG_BUFFER];
	int  bytes;
	int  option;
	
	opterr = 0;
	while ((option = getopt(argc, argv, "hv:p:d:a:t:")) != -1) {
		switch (option) {
			case 'v' :
				if ((sscanf(optarg, "%d", &speed) != 1)
				 || (speed < 50) || (speed > 115200)) {
					fprintf(stderr, "Vitesse %s invalide \n", optarg);
					exit(EXIT_FAILURE);
				}
				break;
			case 'p' :
				parity = optarg[0];
				if ((parity != 'n') && (parity != 'p')
				 && (parity != 'i')) {
					fprintf(stderr, "Parite %c invalide \n", parity);
					exit(EXIT_FAILURE);
				}
				break;
			case 'd' :
				if ((sscanf(optarg, "%d", &data_bits) != 1)
				 || (data_bits < 5) || (data_bits > 8)) {
					fprintf(stderr, "Nb bits donnees %d invalide \n",
							data_bits);
					exit(EXIT_FAILURE);
				}
				break;
			case 'a' :	
				if ((sscanf(optarg, "%d", &stop_bits) != 1)
				 || (stop_bits < 1) || (stop_bits > 2)) {
					fprintf(stderr, "Nb bits arret %d invalide \n",
							stop_bits);
					exit(EXIT_FAILURE);
				}
				break;
			case 't' :
				tty_name = optarg;
				break;
			case 'h' :
				fprintf(stderr, "Syntaxe %s [options]... \n", argv [0]);
				fprintf(stderr, "  Options : \n");
				fprintf(stderr, "     -v <speed en bits/seconde>  \n");
				fprintf(stderr, "     -p <parite> (n)ulle (p)aire (i)mpaire \n");
				fprintf(stderr, "     -d <bits de donnees> (5 a 8) \n");
				fprintf(stderr, "     -a <bits d'arret> (1 ou 2) \n");
				fprintf(stderr, "     -t <nom du peripherique> \n");
				exit(EXIT_SUCCESS);
			default :
				fprintf (stderr, "Option -h pour avoir de l'aide \n");
				exit(EXIT_FAILURE);
		}
	}
	// Ouverture non-bloquante pour basculer en mode non-local
	tty_fd = open(tty_name, O_RDWR | O_NONBLOCK);
	if (tty_fd < 0) {
		perror(tty_name);
		exit(EXIT_FAILURE);
	}
	if (tcgetattr(tty_fd, &config_termios) != 0) {
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	config_termios.c_cflag &= ~ CLOCAL;
	tcsetattr(tty_fd, TCSANOW, & config_termios);
	// Passage du descripteur en mode bloquant
	fcntl(tty_fd, F_SETFL, fcntl(tty_fd, F_GETFL) & ~O_NONBLOCK);
	fprintf(stderr, "Port serie ouvert \n");
	tcgetattr(tty_fd, &config_termios);
	memcpy(& saved_termios, &config_termios, sizeof(struct termios));
	cfmakeraw(&config_termios);
	if (speed < 50)
		setspeed(&config_termios, B50);
	else if (speed < 75)
		setspeed(&config_termios, B75);
	else if (speed < 110)
		setspeed(&config_termios, B110);
	else if (speed < 134)
		setspeed(&config_termios, B134);
	else if (speed < 150)
		setspeed(&config_termios, B150);
	else if (speed < 200)
		setspeed(&config_termios, B200);
	else if (speed < 300)
		setspeed(&config_termios, B300);
	else if (speed < 600)
		setspeed(&config_termios, B600);
	else if (speed < 1200)
		setspeed(&config_termios, B1200);
	else if (speed < 1800)
		setspeed(&config_termios, B1800);
	else if (speed < 2400)
		setspeed(&config_termios, B2400);
	else if (speed < 4800)
		setspeed(&config_termios, B4800);
	else if (speed < 9600)
		setspeed(&config_termios, B9600);
	else if (speed < 19200)
		setspeed(&config_termios, B19200);
	else if (speed < 34000)
		setspeed(&config_termios, B38400);
	else if (speed < 57600)
		setspeed(&config_termios, B57600);
	else 
		setspeed(&config_termios, B115200);
	switch (parity) {
		case 'n' :
			config_termios.c_cflag &= ~ PARENB;
			break;
		case 'p' :
			config_termios.c_cflag |=   PARENB;
			config_termios.c_cflag &= ~ PARODD;
			break;
		case 'i':
			config_termios.c_cflag |=   PARENB;
			config_termios.c_cflag |=   PARODD;
			break;
	}
	config_termios.c_cflag &= ~ CSIZE;
	if (data_bits == 5)
		config_termios.c_cflag |= CS5;
	else if (data_bits == 6)
		config_termios.c_cflag |= CS6;
	else if (data_bits == 7)
		config_termios.c_cflag |= CS7;
	else if (data_bits == 8)
		config_termios.c_cflag |= CS8;
	if (stop_bits == 1)
		config_termios.c_cflag &= ~CSTOPB;
	else
		config_termios.c_cflag |=  CSTOPB;

	config_termios.c_cflag &= ~ CLOCAL;
	config_termios.c_cflag |= HUPCL;
	
	// Controle de flux CTS/RTS specifique Linux
	config_termios.c_cflag |= CRTSCTS;
	
	if (tcsetattr(tty_fd, TCSANOW, &config_termios) < 0) {
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Port serie configure \n");
		
	fprintf(stderr, "Debut de l'envoi des donnees \n");
	while (1) {
		bytes = read(STDIN_FILENO, buffer, LG_BUFFER);
		if (bytes < 0)  {
			perror("read");
			exit(EXIT_FAILURE);
		}
		if (bytes == 0)
			break;
		write(tty_fd, buffer, bytes);
	}
	fprintf(stderr, "Fin de l'envoi des donnees \n");
	sleep(2);
	close(tty_fd);
	// restauration de la config_termios originale
	tty_fd = open(tty_name, O_RDWR | O_NONBLOCK);
	saved_termios.c_cflag |= CLOCAL;
	tcsetattr(tty_fd, TCSANOW, &saved_termios);
	close(tty_fd);

	return EXIT_SUCCESS;
}

