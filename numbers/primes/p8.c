#include <stdio.h>
#include <time.h>
int sieve(int maxnum)
{
	char *primes=malloc(sizeof(char)*maxnum);
	memset(primes,1,sizeof(char)*maxnum);
	int i,j,s;
	for(i=0;i*i<=2*maxnum;i++)
	{
		s=i*2+3;
		if(primes[i])
			for(j=i+s;j<maxnum;j+=s)
				primes[j]=0;
	}
	j=1; //add for 2
	for(i=0;i<maxnum;i++)
		if(primes[i]==1) j++;
	free(primes);
	return j;
}
void test()
{
	int ct=sieve(50000000);
	printf("number: %d\n",ct);
}
int main()
{
	time_t start=clock();
	test();
	printf("total used: %d ms.\n",clock()-start);	
	return 0;
}
