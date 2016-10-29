#include <stdio.h>
#include <string.h>
void test(int t[10])
{
	int j;
	char num[100];
	scanf("%s",&num);
	for(j=0;j<strlen(num);j++)
	{
		t[num[j]-'0']++;
	}
}
void show(int m,int t[10])
{
	int i,y;
	printf("begin painting.\n");
	for(i=0;i<m;i++)
	{
		for(y=0;y<10;y++)
		{
			if(i>=(m-t[y]))printf("*  ");
			else printf("   ");
		}
		printf("\n");
	}
	for(i=0;i<10;i++)
	{
		printf("%-3d",i);
	}
}
int main()
{
	int t[10]={0};
	test(t);
	show(10,t);
	return 0;
}