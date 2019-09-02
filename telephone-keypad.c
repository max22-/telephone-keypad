#include <stdio.h>
#include <ncurses.h>
#include <time.h>

#define KEY_DELAY 1.0

enum EVENT {TICK, KEY0, KEY1, KEY2, KEY3, KEY4, KEY5, KEY6, KEY7, KEY8, KEY9};

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

enum ACTION {GET, RESET};

double timer(enum ACTION action) {
	static time_t start_t, end_t;
	static bool initialized = FALSE;
	if(initialized == FALSE) {
		time(&start_t);
		initialized = TRUE;
	}
	switch(action) {
		case GET:
			time(&end_t);
			return difftime(end_t, start_t);
		case RESET:
			time(&start_t);
			break;
	}
}

int main()
{
    char c;
    initscr();
    clear();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    while((c = getch()) != 'q') {
		if(timer(GET) > KEY_DELAY) {
			timer(RESET);
			stateMachine(TICK);
		}
		mvprintw(1, 0, "%f", timer(GET));
		clrtoeol();
		refresh();
        switch(c) {
            case '0':
				timer(RESET);
				stateMachine(KEY0);
				break;
            case '1':
				timer(RESET);
				stateMachine(KEY1);
				break;			
            case ERR:
                break;
            default:
                mvprintw(0, 0, "Foo bar");
                clrtoeol();
                refresh();
                break;
        }
    }
    endwin();
    return 0;
}
