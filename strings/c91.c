/*
 * windows c console painter using pdcurses.
 * animation drawing demo.
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
	for(i=0; i<mh+1; i++) tb[i*(mw+1)+mw]='\n';
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
		for(i=y1; i!=y2; i+=dir) point(x1,i,pen);
	}
	else
	{
		d=(y2-y1)/(double)(x2-x1);
		if(abs(d)<1)
		{
			if(x2<x1)dir=-1;
			for(i=x1; i!=x2; i+=dir) point(i,y1+(i-x1)*d,pen);
		}
		else
		{
			if(y2<y1)dir=-1;
			for(i=y1; i!=y2; i+=dir) point(x1+(i-y1)/d,i,pen);
		}
	}
}
void text(int x,int y, char* t)
{
	int i;
	for(i=0; i<strlen(t); i++) point(x+i,y,t[i]);
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
	for(i=0; i<6.28*r; i++) point(x+r*2*cos(i/(double)r),y+r*sin(i/(double)r),pen);
}
void circlerand(int x,int y,int r)
{
	int i;
	for(i=0; i<6.28*r; i++) point(x+r*2*cos(i/(double)r),y+r*sin(i/(double)r),RAND_CHAR);
}
void ball(int x,int y,int r,char pen)
{
	int i;
	for(i=1; i<r; i++) circle(x,y,i,pen);
}
void ballrand(int x,int y,int r)
{
	int i;
	for(i=0; i<r; i++) circlerand(x,y,i);
}
void ballrand2(int x,int y,int r)
{
	int i;
	for(i=0; i<r; i++) circle(x,y,i,RAND_CHAR);
}
//ball animation
int br=5;
double bx=40,by=10,bvx=0,bvy=0,bax=0.1,bay=0.1;
int br2=4;
double bx2=60,by2=15,bvx2=0,bvy2=0,bax2=-0.1,bay2=0.1;
bool ishit()
{
	int dist=(bx-bx2)*(bx-bx2)/2.0+(by-by2)*(by-by2);
	return dist<(br+br2)*(br+br2);
}
void update(int n)
{
	bvx+=bax;bx+=bvx;
	bvy+=bay;by+=bvy;
	if((bx-br)<0||(bx+br)>mw)
	{
		bx-=bvx;bvx=-bvx;
		bax=rand()%10/50.0-0.1;
	}
	if((by-br/2.0)<0||(by+br)>mh+br/2.0)
	{
		by-=bvy;bvy=-bvy;
		bay=rand()%10/50.0-0.1;
	}
	//ball2
	bvx2+=bax2;bvy2+=bay2;
	bx2+=bvx2;by2+=bvy2;
	
	if((bx2-br2)<0||(bx2+br2)>mw)
	{
		bx2-=bvx2;
		bvx2=-bvx2;
		bax2=rand()%10/50.0-0.1;
	}
	if((by2-br2/2.0)<0||(by2+br2)>mh+br2/2.0)
	{
		by2-=bvy2;bvy2=-bvy2;
		bay2=rand()%10/50.0-0.1;
	}
	if(ishit())
	{
		bx-=bvx;by-=bvy;
		bx2-=bvx2;by2-=bvy2;
		bvx=-bvx;bax=-bax;
		bvx2=-bvx2;bax2=-bax2;
		bvy=-bvy;bay=-bay;
		bvy2=-bvy2;bay2=-bay2;
	}
}
void draw()
{
	cleardata();
	ball(bx2,by2,br2,'.');
	ballrand2(bx,by,br);
	bg();
	show();
}
void graph()
{
	int t=0;
	tb=(char*)malloc(msize*sizeof(char));
	while(1)
	{
		update(t);
		draw();
		_sleep(40);
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
