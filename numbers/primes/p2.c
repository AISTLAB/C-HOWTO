#include <stdio.h>
#include <time.h>
int isprime(int n)
{
	if(n==2||n==3) return 1;
	if(n%2==0 || n<2) return 0;
	int i;
	for(i=3;i*i<=n;i+=2)
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
