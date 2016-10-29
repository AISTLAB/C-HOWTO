#include <stdio.h>
#include <time.h>
#include <math.h>
int isprime(int n)
{
	if(n<2)return 0;
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}
void test()
{
	int i,ct=0;
	for(i=1;i<1000000;i++)
	{
		if(isprime(i)==1) ct++;	
	}
	printf("number: %d\n",ct);
}
int main()
{
	time_t start=clock();
	test();
	printf("total used: %d ms.\n",clock()-start);	
	return 0;
}
