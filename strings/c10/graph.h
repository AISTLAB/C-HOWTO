#pragma once
#include "common.h"
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
void circle(int x,int y,int r,char pen)
{
	int i;
	for(i=0;i<6.28*r;i++)
	{
		point(x+r*2*cos(i/(double)r),y+r*sin(i/(double)r),pen);
	}
}
void circlerand(int x,int y,int r)
{
	int i;
	for(i=0;i<6.28*r;i++)
	{
		point(x+r*2*cos(i/(double)r),y+r*sin(i/(double)r),RAND_CHAR);
	}
}
void ball(int x,int y,int r,char pen)
{
	int i;
	for(i=1;i<r;i++)
		circle(x,y,i,pen);
}
void ballrand(int x,int y,int r)
{
	int i;
	for(i=0;i<r;i++)
		circlerand(x,y,i);

}
void ballrand2(int x,int y,int r)
{
	int i;
	for(i=0;i<r;i++)
		circle(x,y,i,RAND_CHAR);

}
void board()
{
	line(10,0,mw,0,'-');
	line(10,mh-1,mw,mh-1,'-');
	line(10,0,10,mh,'|');
	line(mw-1,0,mw-1,mh,'|');
}
void blow(int x,int y)
{
	int i;
	for(i=1;i<3;i++)
	{
		circlerand(x,y,i);
		refresh();
	}
}