#include <stdio.h>
void test()
{
	int num=0,j;
	int t[10]={0};
	scanf("%d",&num);
	while(num)
	{
		t[num%10]++;
		num/=10;
	}
	for(j=0;j<10;j++)
	{
		printf("%d ",t[j]);
	}
}
int main()
{
	test();
	return 0;
}