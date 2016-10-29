#include <stdio.h>
#include <time.h>
int sieve(int maxnum)
{
	char *primes=malloc(sizeof(char)*maxnum);
	memset(primes,1,sizeof(char)*maxnum);
	int i,j;
	for(i=2;i*i<maxnum;i++)
	{
		if(primes[i]==1)
		{
			j=2;
			while(j*i<maxnum) primes[i*j++]=0;		
		}
	}
	j=0;
	for(i=2;i<maxnum;i++)
		if(primes[i]==1) j++;
	free(primes);
	return j;
}
void test()
{
	int ct=sieve(100000000);
	printf("number: %d\n",ct);
}
int main()
{
	time_t start=clock();
	test();
	printf("total used: %d ms.\n",clock()-start);	
	return 0;
}
