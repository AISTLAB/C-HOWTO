#include <iostream>
#include <ctime>
using namespace std;
int *primes;
int *goldbachs;
int maxn=1000000;
bool isprime(int n)
{
	if(n==2 || n==3)return 1;
	if(n<2 || n%2==0)return 0;
	for(int i=3;i*i<=n;i+=2)
	{
		if(n%i==0)return 0;
	}
	return 1;
}
void goldbach(int n)
{
	int ct=0;
	for(int i=0;primes[i]*2<n;i++)
	{
		for(int j=i;primes[i]+primes[j]<n;j++)
		{
			goldbachs[primes[i]+primes[j]]++;
		}
	}
}
void init()
{
	primes=new int[maxn];
	goldbachs=new int[maxn];
	memset(goldbachs,0,maxn*sizeof(int));
	int ct=0;
	for(int i=3;i<maxn*1.01;i+=2)
	{
		if(isprime(i))
		{
			primes[ct++]=i;
		}	
	}
	cout<<"init finished."<<endl;
}
int main()
{
	time_t st=clock();
	init();
	goldbach(maxn);
	int m=0;
	for(int i=6;i<maxn;i+=2)
	{
		if(goldbachs[i]>m)
		{
			m=goldbachs[i];		
			cout<<i<<","<<m<<endl;
		}
	}
	cout<<"biggest:"<<m<<endl;
	cout<<"used:"<<clock()-st<<"ms"<<endl;
	return 0;
}
