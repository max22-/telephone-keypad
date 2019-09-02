#include "state-machine.h"
#include <ncurses.h>

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
		case KEY2:
			mvprintw(0,0, "2");
			clrtoeol();
			refresh();
			break;
		case KEY3:
			mvprintw(0,0, "3");
			clrtoeol();
			refresh();
			break;
		case KEY4:
			mvprintw(0,0, "4");
			clrtoeol();
			refresh();
			break;
		case KEY5:
			mvprintw(0,0, "5");
			clrtoeol();
			refresh();
			break;
		case KEY6:
			mvprintw(0,0, "6");
			clrtoeol();
			refresh();
			break;
		case KEY7:
			mvprintw(0,0, "7");
			clrtoeol();
			refresh();
			break;
		case KEY8:
			mvprintw(0,0, "8");
			clrtoeol();
			refresh();
			break;
		case KEY9:
			mvprintw(0,0, "9");
			clrtoeol();
			refresh();
			break;
	}
}
