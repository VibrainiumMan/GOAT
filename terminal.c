#include <ctype.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "terminal.h"

/*
This does some thing that I'm suppose to know.
Fuck is half of this bullshit. Time to hang myself!

Doing a $19 Fortnite giftcard giveaway, who wants it? 
*/

static struct termios original_terminal;

void die(const char *s) {
	perror(s);
	exit(1);
}

void exit_raw_mode(){
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_terminal) == 1) {
	    die("tcsetattr");
	}
}

void enter_raw_mode(){
	if(tcgetattr(STDIN_FILENO, &original_terminal) == -1) {
		die("tcgetattr");
	}

	atexit(exit_raw_mode);

	struct termios raw = original_terminal;
	

	// Input Flags
	raw.c_cflag &= ~(CS8);
	raw.c_iflag &= ~(IXON | ICRNL | INPCK | ISTRIP);
	raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;

	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
		die("tcsetattr");
	}
}

// Does something IDK
char read_key() {
	int nread;
	char c;

	while((nread = read(STDIN_FILENO, &c, 1)) != 1) {
		if(nread == -1 && errno != EAGAIN) {
			die("read");
		}
	}
	return c;
}

void process_key() {
	char c = read_key(); // IDK what this does

	switch(c) {
		case CTRL_KEY('q'): // Process 'control + q' to exit the program
			exit(0);
			break;
	}
}

// Clears screen
void refresh_display() {
	write(STDOUT_FILENO, "\x1b[2J", 4); // I don't know what this does
}
