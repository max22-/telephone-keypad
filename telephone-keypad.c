#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include "timer.h"
#include "state-machine.h"

#define KEY_DELAY 1.0

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
