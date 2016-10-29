//linear step sieve
#include <iostream>
#include <ctime>
using namespace std;
#define maxn 10000000
int main()
{
	time_t st=clock();
	bool *ps=new bool[maxn];
	memset(ps,1,sizeof(bool)*maxn);
	int gap1=4,gap2=4; //filter 2' and 3' 
	for(int i=5;i*i<=maxn;i+=gap1) //
	{
		if(ps[i]) //
		{
			long long p=i; //if bigger, p should be long long
			while(1)
			{
				gap2=6-gap1;
				for(int j=i+gap2;j*p<maxn;j+=gap2)
				{
					if(ps[j]) ps[j*p]=0; //sieve for p1^n*p2
					gap2=6-gap2;
				}
				p*=i;
				if(p>=maxn)break;
				ps[p]=0; //sieve for p1^n
			}
		}
		gap1=6-gap1;
	}
	int ct=2; //for 2 and 3
	gap1=4;
	for(int j=5;j<maxn;gap1=6-gap1,j+=gap1)
	{
		if(ps[j])ct++; 
	}
		
	delete ps;
	cout<<"used:"<<clock()-st<<endl<<"total: "<<ct<<endl;
	return 0;
}
