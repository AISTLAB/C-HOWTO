#include <iostream>
#include <ctime>
using namespace std;
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
int goldbach(int n)
{
	if(n%2==1||n<6)return 0;
	int ct=0;
	for(int i=3;i*2<=n;i+=2)
	{
		if(isprime(i) && isprime(n-i))
		{
			ct++;
		}	
	}
	return ct;
}
int main()
{
	time_t st=clock();
	int m=0;
	for(int i=6;i<100000;i+=2)
	{
		if(goldbach(i)>m)
		{
			m=goldbach(i);
			cout<<i<<","<<m<<endl;
		}
	}
	cout<<"biggest:"<<m<<endl;
	cout<<"used:"<<clock()-st<<"ms"<<endl;
	return 0;
}
