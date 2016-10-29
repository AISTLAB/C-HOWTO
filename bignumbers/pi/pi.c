/*
using Machin' formula calculate pi.
PI=16atan(1/5)-4atan(1/239)
winxos 2012-10-19
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define base 1000000000
#define baselen 9
#define CLEAR(x) memset(x,0,mlen*sizeof(int))
#define INIT(x) x=(int*)malloc(sizeof(int)*mlen); CLEAR(x)

int mlen = 120; //mlen*baselen is the total digits.
typedef int* BIG; //big struct
void show(int *t) //format print
{
	int i=mlen-1;
	while(i>0 && !t[i])i--;
	printf("%d,\n",t[i]);
	for(i--;i>=0;i--) printf("%09d ",t[i]);
	printf("\n");
}
int sdiv(BIG a,int b) //big div small int stored at a
{
	int i=mlen-1;
	while(!a[i])i--;
	int remain=0; //c99
	for(;i>=0;i--) //not include the last.
	{
		long long tmp=(long long)remain*base+a[i];
		a[i]=tmp/b;
		remain=tmp%b;
	}
	return a[0]%b; //return remainder
}
int smul(BIG a,int b) //product a by b stored at a
{
	int s=mlen-1;
	while(!a[s])s--;
	int carry=0; 
	for(int i=0;i<=s+1;i++)
	{
		long long tmp=(long long)a[i]*b+carry;
		carry=tmp/base;
		a[i]=tmp%base;
	}
	return carry;
}
int length(BIG a) //digits length in decimal
{
	int s=mlen-1;
	while(s && !a[s])s--;
	int i=0,n=a[s];
	while (n)
	{
		n/=10;
		i++;
	}
	return i+s*baselen;
}
void verify(BIG a) //check the carry or bolower
{
	for(int i=0;i<mlen;i++)
	{
		if(a[i]>=base)
		{
			a[i]-=base;
			a[i+1]+=1;
		}
		else if(a[i]<0)
		{
			a[i]+=base;
			a[i+1]-=1;
		}
	}
}
int saddsub(BIG a,BIG b,int op) //add or sub b to a stored at a
{
	int s=mlen-1;
	while(!b[s])s--;
	int i,carry=0; 
	for(i=0;i<=s+1;i++)
	{
		if(op==1)a[i] += b[i];
		else if(op==-1)a[i] -= b[i];
	}
	verify(a);
}
BIG satan(int ang) // atan= x -  1/3 x^3 + 1/5 x^5 ...
{
	BIG sum,b,c;
	INIT(sum);INIT(b);INIT(c);
	b[mlen-1]=1;
	sdiv(b,ang); //b = 1/x;
	memcpy(sum,b,mlen*sizeof(int));
	int d=-1;
	for(int i=1;i<mlen*6.5;i++) //about 6.5 can reach the precision
	{
		int t=2*i+1;
		sdiv(b,ang*ang);
		memcpy(c,b,mlen*sizeof(int));
		sdiv(c,t);
		saddsub(sum,c,d);
		d=-d;
	}
	return sum;
}
void PI()
{
	clock_t begin,end;
	begin=clock();
	
	BIG a,b;
	INIT(a);INIT(b);
	a=satan(5);
	smul(a,16);
	b=satan(239);
	smul(b,4);
	saddsub(a,b,-1);
	
	end=clock();
	printf("digits:%d, used:%d ms.\n",length(a),end-begin);
	show(a);
}
int main()
{
	int num;
	while(1)
	{
		printf("输入计算位数:");
		scanf("%d",&num);
		mlen=(num+20)/9;
		PI();
	}
	return 0;
}