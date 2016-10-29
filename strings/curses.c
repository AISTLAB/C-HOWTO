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
	int i,j;
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
	tb[y*(mw+1)+x]=pen;
}
void line(int x1,int y1,int x2,int y2,char pen)
{
	double d;
	int i;
	if(x2==x1) 
	{
		for(i=y1;i<=y2;i++)
		{
			point(x1,i,pen);
		}
	}
	else
	{
		d=(y2-y1)/(double)(x2-x1);
		for(i=x1;i<=x2;i++)
		{
			point(i,y1+(i-x1)*d,pen);
		}
	}

}
int f(int x)
{
	int ans=0;
	if(x%10<5)ans=5;
	else ans=-5;
	return ans;
}
void run(int x)
{
	int i,j;
	cleardata();
	for(i=0;i<mw;i++)
	{
		point(i,sin((i+x)/10.0)*10+mh/2,'*');
		point((i+x)%mw,f(i)+mh/2,'#');
	}
	for(i=0;i<14;i++)
	line((5*i+x)%mw,-5+mh/2,(5*i+x)%mw,5+mh/2,'#');
	
}
void graph()
{
	int t=0;
	tb=(char*)malloc(msize*sizeof(char));
	while(1)
	{
		run(t);
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