#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
const int mp=80000;
const int mg=1000000;
int *primes; //odd primes
int *goldbachs; //bach ans
void initprimes()
{
	int i,j,ct=0;
	char *temp=(char *)malloc(sizeof(char)*mg);
	primes=(int *)malloc(sizeof(int)*mp);
	memset(temp,1,sizeof(char)*mg);
	for(i=3;i*i<mg;i+=2)
	{
		if(temp[i]==1)
		{
			j=i;
			while(j*i<mg)
			{
				temp[i*j]=0;
				j+=2;
			}
		}
	}	
	for(i=3;i<mg;i+=2)
	{
		if(temp[i]==1) primes[ct++]=i;
	}
	free(temp); 
	printf("init %d\nwaiting...\n",ct);
}
void goldbach()
{
	int i,j;
	goldbachs=(int *)malloc(sizeof(int)*mg);
	memset(goldbachs,0,sizeof(int)*mg);
	for(i=0;primes[i]<mg/2;i++)
	{
		for(j=i;;j++)
		{
			if(primes[j]==0 || (primes[j]+primes[i])>mg)
				break;
			goldbachs[primes[j]+primes[i]]++;
		}
	}
	j=0; //max
	for(i=6;i<mg;i+=2)
	{
		if(goldbachs[i]>j)
		{
			j=goldbachs[i];
			printf("max:%d %d\n",i,j);
		}	
	}
}
int main()
{
	time_t st=clock();
	initprimes();
	goldbach();	
	printf("used: %d ms.",clock()-st);
	return 0;
}
