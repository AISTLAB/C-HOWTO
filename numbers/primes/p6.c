#include <stdio.h>
#include <time.h>
#define maxnum 80000
int *primes;
int isprime(int n)
{
	if(n==2||n==3) return 1;
	if(n%2==0 || n<2 || n%3==0) return 0;
	int i,gap=4,p=3;
	for(i=5;i*i<=n;)
	{
		if(n%i==0) return 0;
		if(primes[p]>0)
		{
			i=primes[p++];
		}
		else
		{
			gap=6-gap;
			i+=gap;
		}
	}
	return 1;
}
void test()
{
	primes=malloc(sizeof(int)*maxnum);
	int i,ct=0;
	for(i=1;i<1000000;i++)
	{
		if(isprime(i)==1)
		{
			primes[ct]=i;
			ct++;	
		}
	}
	printf("the 10th prime is: %d\n",primes[10]);
	printf("number: %d\n",ct);
	free(primes);
}
int main()
{
	time_t start=clock();
	test();
	printf("total used: %d ms.\n",clock()-start);	
	return 0;
}
