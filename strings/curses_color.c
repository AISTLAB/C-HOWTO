#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define mw 70
#define mh 24
chtype* tb[mh];
void show()
{
	int i,j;
	clear();
	for(i=0;i<mh;i++)
	{
		for(j=0;j<mw;j++)
		{
			addch(tb[i][j]);
		}
		addch('\n');
	}
	refresh();
}
void init()
{
	int i,j;
	for(i=0;i<mh;i++)
	{
		tb[i]=(chtype*)malloc((mw+1)*sizeof(chtype));
		for(j=0;j<mw;j++)
		{
			tb[i][j]='.';
		}
		tb[i][mw]=0; //×Ö·û´®½áÎ²·ûºÅ
	}
	start_color();
	init_pair(1,COLOR_RED,COLOR_BLACK);
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);

}
void run(int x)
{
	tb[rand()%mh][rand()%mw]=(rand()%26+'A')|COLOR_PAIR(rand()%3);
}
void graph()
{
	int t=0;
	init();
	while(1)
	{
		run(t);
		show();
		t++;
	}
}
void test()
{
	chtype *c=(chtype*)malloc(10*sizeof(chtype));
	start_color();
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	c[0]='a'|COLOR_PAIR(1);
	c[1]='b'|COLOR_PAIR(2);
	c[3]='b'|COLOR_PAIR(2);
	addchstr(c);
	refresh();
}
int main()
{
	initscr();
	noecho();
	cbreak();
	graph();
	getch();
	endwin();
	return 0;
}