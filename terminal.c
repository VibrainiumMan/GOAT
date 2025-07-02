#include <termios.h>
#include "terminal.h"

/*
This does some thing that I'm suppose to know.
Fuck is half of this bullshit. Time to hang myself!

Doing a $19 Fortnite giftcard giveaway, who wants it? 
*/

static struct termios original_terminal;

void exit_raw_mode(){
	tcsetattr(STDIN)FILENO, TCSAFLUSH, &original_terminal);
}

void enter_raw_mode(){
	
}
