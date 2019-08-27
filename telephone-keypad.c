#include <stdio.h>
#include <ncurses.h>

int main()
{
    char c;
    initscr();
    clear();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    while((c = getch()) != 'q') {
        switch(c) {
            case 'a':
                mvprintw(0,0, "Hello, world !");
                clrtoeol();
                refresh();
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
