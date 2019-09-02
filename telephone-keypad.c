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
            case '2':
				timer(RESET);
				stateMachine(KEY2);
				break;
            case '3':
				timer(RESET);
				stateMachine(KEY3);
				break;
            case '4':
				timer(RESET);
				stateMachine(KEY4);
				break;
            case '5':
				timer(RESET);
				stateMachine(KEY5);
				break;
            case '6':
				timer(RESET);
				stateMachine(KEY6);
				break;
            case '7':
				timer(RESET);
				stateMachine(KEY7);
				break;
            case '8':
				timer(RESET);
				stateMachine(KEY8);
				break;
            case '9':
				timer(RESET);
				stateMachine(KEY9);
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
