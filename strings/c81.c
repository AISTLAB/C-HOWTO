#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
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
	memset(tb,' ',msize);
	for(i=0;i<mh+1;i++)
	{
		tb[i*(mw+1)+mw]='\n';
	}
	tb[msize]=0;
}
void point(int x,int y,char pen)
{
	if(x<0||y<0||x>=mw||y>=mh)return;
	tb[y*(mw+1)+x]=pen;
}
void line(int x1,int y1,int x2,int y2,char pen)
{
	double d;
	int i,dir;
	if(x2==x1) 
	{
		dir=1;
		if(y2<y1)dir=-1;
		for(i=y1;i!=y2;i+=dir)
		{
			point(x1,i,pen);
		}
	}
	else
	{
		d=(y2-y1)/(double)(x2-x1);
		dir=1;
		if(abs(d)<1)
		{
			if(x2<x1)dir=-1;
			for(i=x1;i!=x2;i+=dir)
			{
				point(i,y1+(i-x1)*d,pen);
			}
		}
		else
		{
			dir=1;
			if(y2<y1)dir=-1;
			for(i=y1;i!=y2;i+=dir)
			{
				point(x1+(i-y1)/d,i,pen);
			}
		}
	}

}
void text(int x,int y, char* t)
{
	int i;
	for(i=0;i<strlen(t);i++)
	{
		point(x+i,y,t[i]);
	}
}
void textn(int x,int y,int n)
{
	char buf[10];
	itoa(n,buf,10);	
	text(x,y,buf);
}
int f(int x)
{
	int ans=0;
	if(x%10<5)ans=5;
	else ans=-5;
	return ans;
}
void bg(int x)
{
	int i,j;
	cleardata();
	for(i=0;i<10;i++)
		point(rand()%mw,rand()%mh,rand()%70+'A');
}
void tclock(int x)
{
	int hr,mi,se,i;
	time_t t=time(0);
	struct tm tms=*localtime(&t);

	hr=tms.tm_hour;
	mi=tms.tm_min;
	se=tms.tm_sec;

	line(mw/2,mh/2,mw/2+15*cos(6.28-(se-15)*6/57.3),mh/2-10*sin(6.28-(se-15)*6/57.3),'.');
	line(mw/2,mh/2,mw/2+10*cos(6.28-(mi-15)*6/57.3),mh/2-10*sin(6.28-(mi-15)*6/57.3),'x');
	line(mw/2,mh/2,mw/2+7*cos(6.28-(hr+mi/60.0-3)*30/57.3),mh/2-7*sin(6.28-(hr+mi/60.0-3)*30/57.3),'@');
	for(i=1;i<13;i++)
	{
		textn(mw/2+(18+(x/10)%3)*cos((i-3)*30/57.3),mh/2+(7+(x/10)%3)*sin((i-3)*30/57.3),i);
	}
}
void graph()
{
	int t=0;
	tb=(char*)malloc(msize*sizeof(char));
	cleardata();
	while(1)
	{
		bg(t);
		tclock(t);
		show();
		_sleep(50);
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