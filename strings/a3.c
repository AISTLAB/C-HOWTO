#include <stdio.h>
void test()
{
	int i,j;
	char num[100]={0};
	int t[10]={0};
	scanf("%s",&num);
	for(j=0;num[j]!=0;j++)
	{
		t[num[j]-'0']++;
	}
	for(j=0;j<10;j++)
	{
		printf("%d:",j);
		for(i=0;i<t[j];i++)
		{
			printf("*");
		}
		printf("%d\n",t[j]);
	}
}
int main()
{
	test();
	return 0;
}