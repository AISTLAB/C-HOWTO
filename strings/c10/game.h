#pragma once
#include "common.h"

bool isover=FALSE;
int bw=7;
double bx=30,bvx=0;
struct bullet
{
	double x,y,vx,vy;
}bs;
typedef struct
{
	int x,y;
	char shape;
}monster;
#define monsternum 50
monster mon[monsternum];
int score=0;
void createmonster()
{
	int i;
	for(i=0;i<monsternum;i++)
	{
		mon[i].x=rand()%(mw-bw)+bw/2+10;
		mon[i].y=rand()%10+1;
		mon[i].shape=RAND_NUM;
	}
}
void monstermove()
{
	int i;
	for(i=0;i<monsternum;i++)
	{
		mon[i].x+=(int)(rand()%3-1)*(rand()%10<4);
		mon[i].y+=(int)(rand()%3-1)*(rand()%10<2);
		if(mon[i].x<11)mon[i].x=11;
		if(mon[i].y<1)mon[i].y=1;
		if(mon[i].x>mw-bw/2)mon[i].x=mw-bw/2;
		if(mon[i].y>10)mon[i].y=10;
	}
}
bool ishit()
{
	int i;
	for(i=0;i<monsternum;i++)
	{
		if(mon[i].shape && (int)bs.x==mon[i].x && (int)bs.y==mon[i].y)
		{
			blow(mon[i].x,mon[i].y);
			mon[i].shape=0;
			bs.y=-1;
			score+=10;
			return TRUE;
		}
	}
	return FALSE;
}

void fire()
{
	bs.x=bx+bw/2;
	bs.y=mh-2;
	bs.vy=rand()%10/10-1;
}
void update(int n)
{
	int ch=getch();
	switch(ch)
	{
	case KEY_LEFT:
		bvx+=-0.3;
		break;
	case KEY_RIGHT:
		bvx+=0.3;
		break;
	case 27:
		isover=TRUE;
		break;
	case ' ':
		if(bs.y<=0)
			fire();
		break;
	default:
		bvx*=0.9;
		break;
	}
	bx+=bvx;
	if(bx<11)
	{
		bx=11;
		bvx=0;
	}
	if(bx>=mw-bw)
	{
		bx=mw-bw-1;
		bvx=0;
	}

	bs.y+=bs.vy;
	if(bs.y<0)bs.vy=0;

	ishit();
	monstermove();
}
void draw()
{
	int i;
	cleardata();
	line(bx,mh-2,bx+bw,mh-2,'M');
	line(bx+2,mh-3,bx+bw-2,mh-3,'H');
	board();
	textn(0,8,(int)bvx);
	textn(0,10,(int)bx);
	if(bs.y>0)
	{
		point(bs.x,bs.y,'^');
	}
	for(i=0;i<monsternum;i++)
	{
		if(mon[i].shape)
			point(mon[i].x,mon[i].y,mon[i].shape);
	}
	text(0,0,"score:");
	textn(2,1,score);
}
void run()
{
	int t=0;
	tb=(char*)malloc(msize*sizeof(char));
	createmonster();
	while(!isover)
	{
		draw();
		update(t);
		show();
		_sleep(20);
		t++;
	}
	clear();
}
