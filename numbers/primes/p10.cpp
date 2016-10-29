//linear odd sieve
#include <iostream>
#include <ctime>
using namespace std;
#define maxn 1000000
int main()
{
	time_t st=clock();
	bool *ps=new bool[maxn/2];
	memset(ps,1,sizeof(bool)*maxn/2);
	int n=0;
	long long p=0;
	for(int i=1;n*n<=maxn;i++) 
	{
		n=(2*i+1);
		if(ps[i])
		{
			p=n; //if bigger, p should be long long
			while(1)
			{
				int j=i+1;
				while((2*j+1)*p<maxn)
				{
					if(ps[j])ps[(2*j+1)*p>>1]=0; //sieve for p1^n*p2
					j++;
				}
				p*=n;
				if(p>=maxn)break;
				ps[p>>1]=0; //sieve for p1^n
			}
		}
	}
	int ct=1;
	for(int j=1;j<maxn/2;j++)
		if(ps[j])ct++;
	delete ps;
	cout<<"used:"<<clock()-st<<endl<<ct<<endl;
	return 0;
}
