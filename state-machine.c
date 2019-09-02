#include "state-machine.h"

void stateMachine(enum EVENT event) {
	switch(event) {
		case TICK:
			mvprintw(0,0, "TICK");
			clrtoeol();
			refresh();
			break;
		case KEY0:	
			mvprintw(0,0, "0");
			clrtoeol();
			refresh();
			break;
		case KEY1:	
			mvprintw(0,0, "1");
			clrtoeol();
			refresh();
			break;
		
	}
}
