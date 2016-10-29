
#include "graph.h"
#include "game.h"

int main()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	timeout(5);
	curs_set(0);
	mvprintw(10,20,"Fight Monster.");
	mvprintw(12,35,"HAVE FUN.");
	mvprintw(14,45,"2012-10-18.");
	refresh();
	_sleep(2000);
	run();

	endwin();
	printf("end.");
	getch();
	return 0;
}