/*
 * windows c console simulator clock using pdcurses.
 */
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#define mw 70
#define mh 24
#define msize (mw+1)*mh
char *tb;
void show()
{
	clear();
	addstr(tb);
	refresh();
}
void cleardata()
{
	int i;
	memset(tb,' ',msize*sizeof(char));
	for(i=0; i<mh+1; i++)
	{
		tb[i*(mw+1)+mw]='\n';
	}
	tb[msize]=0;
}
void point(int x,int y,char pen)
{
	if(x<0 || y<0 || x>=mw || y>=mh) return;
	tb[y*(mw+1)+x]=pen;
}
void line(int x1,int y1,int x2,int y2,char pen) //µ›πÈ÷±œﬂÀ„∑®
{
	if(abs(x1-x2)<2 && abs(y1-y2)<2) return;
	int cx=(x1+x2)/2,cy=(y1+y2)/2;
	point(cx,cy,pen);
	line(x1,y1,cx,cy,pen);
	line(cx,cy,x2,y2,pen);
}
void bg(int x)
{
	int i;
	for(i=0; i<100; i++)
	{
		point(rand()%mw,rand()%mh,rand()%70+'A');
	}
}
void tclock(int x)
{
	int hr,mi,se,i;
	time_t t=time(0);
	struct tm tms=*localtime(&t); //get time
	hr=tms.tm_hour;
	mi=tms.tm_min;
	se=tms.tm_sec;
	line(mw/2,mh/2,mw/2+15*cos(6.28-(se-15)*6/57.3),mh/2-10*sin(6.28-(se-15)*6/57.3),'.'); //second
	line(mw/2,mh/2,mw/2+10*cos(6.28-(mi-15)*6/57.3),mh/2-10*sin(6.28-(mi-15)*6/57.3),'o'); //minute
	line(mw/2,mh/2,mw/2+7*cos(6.28-(hr+mi/60.0-3)*30/57.3),mh/2-7*sin(6.28-(hr+mi/60.0-3)*30/57.3),'#'); //hour
	for(i=0; i<360; i+=6)
	{
		point(mw/2+18*cos(i/57.3),mh/2+10*sin(i/57.3),'~');
	}
}
void graph()
{
	int t=0;
	tb=(char*)malloc(msize*sizeof(char));
	while(1)
	{
		cleardata();
		bg(t);
		tclock(t);
		show();
		_sleep(10);
		t++;
	}
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
