#include <stdio.h>
#include "terminal.h"

int main(){
	enter_raw_mode();
	
	while(1) {
	    refresh_display();
	    process_key();
	}

	return 0; 
}
