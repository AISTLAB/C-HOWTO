/*
 * windows c console painter using pdcurses.
 * drawing demo.
 */
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#define mw 70
#define mh 24
#define msize (mw+1)*mh
//MARCO
#define RAND_CHAR rand()%60+'A'
#define RAND_NUM rand()%10+'0'
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
	for(i=0;i<mh+1;i++) tb[i*(mw+1)+mw]='\n';
}
void point(int x,int y,char pen)
{
	if(x<0||y<0||x>=mw||y>=mh)return;
	tb[y*(mw+1)+x]=pen;
}
void line(int x1,int y1,int x2,int y2,char pen)
{
	double d;
	int i,dir=1;
	if(x2==x1) 
	{
		if(y2<y1)dir=-1;
		for(i=y1;i!=y2;i+=dir) point(x1,i,pen);
	}
	else
	{
		d=(y2-y1)/(double)(x2-x1);
		if(abs(d)<1)
		{
			if(x2<x1)dir=-1;
			for(i=x1;i!=x2;i+=dir) point(i,y1+(i-x1)*d,pen);
		}
		else
		{
			if(y2<y1)dir=-1;
			for(i=y1;i!=y2;i+=dir) point(x1+(i-y1)/d,i,pen);
		}
	}
}
void text(int x,int y, char* t)
{
	int i;
	for(i=0;i<strlen(t);i++) point(x+i,y,t[i]);
}
void textn(int x,int y,int n)
{
	char buf[10];
	itoa(n,buf,10);	
	text(x,y,buf);
}
void bg()
{
	line(0,0,mw,0,'-');
	line(0,mh-1,mw,mh-1,'-');
	line(0,0,0,mh,'|');
	line(mw-1,0,mw-1,mh,'|');
}
void circle(int x,int y,int r,char pen)
{
	int i;
	for(i=0;i<6.28*r;i++) point(x+r*2*cos(i/(double)r),y+r*sin(i/(double)r),pen);
}
void circlerand(int x,int y,int r)
{
	int i;
	for(i=0;i<6.28*r;i++) point(x+r*2*cos(i/(double)r),y+r*sin(i/(double)r),RAND_CHAR);
}
void ball(int x,int y,int r,char pen)
{
	int i;
	for(i=1;i<r;i++) circle(x,y,i,pen);
}
void ballrand(int x,int y,int r)
{
	int i;
	for(i=0;i<r;i++) circlerand(x,y,i);
}
void ballrand2(int x,int y,int r)
{
	int i;
	for(i=0;i<r;i++) circle(x,y,i,RAND_CHAR);
}
void graph()
{
	int t=0;
	tb=(char*)malloc(msize*sizeof(char));
	while(1)
	{
		cleardata();
		bg();
		circle(10,6,5,'*');
		circlerand(50,6,5);
		ball(50,15,3,'.');
		ballrand(60,15,3);
		ballrand2(20,15,3);
		show();
		_sleep(20);
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
