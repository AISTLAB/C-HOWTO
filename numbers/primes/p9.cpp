//linear sieve
#include <iostream>
#include <ctime>
using namespace std;
#define maxn 100000000
int main()
{
	time_t st=clock();
	bool *ps=new bool[maxn];
	memset(ps,1,sizeof(bool)*maxn);
	for(int i=2;i*i<=maxn;i++) 
	{
		if(ps[i])
		{
			long long p=i; //if bigger, p should be long long
			while(1)
			{
				for(int j=i+1;j*p<maxn;j++)
				{
					if(ps[j])ps[j*p]=0; //sieve for p1^n*p2
				}
				p*=i;
				if(p>=maxn)break;
				ps[p]=0; //sieve for p1^n
			}
		}
	}
	int ct=0;
	for(int j=2;j<maxn;j++)
		if(ps[j])ct++;
	delete ps;
	cout<<"used:"<<clock()-st<<endl<<ct<<endl;
	return 0;
}
