#include <time.h>
#include <ncurses.h>
#include "timer.h"

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
	return 0.0;
}
