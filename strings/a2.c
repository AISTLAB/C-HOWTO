#include <stdio.h>
void test ()
{
	int  j=0;
	char num[100]={0}; //静态数组，最大输入字符数。
	int t[10]={0};
	scanf("%s",&num);
    for (j=0;num[j]!=0;j++)
	{
		t[num[j]-48]++;
	}
	for (j=0;j<10;j++)
	{
		printf("%d:%d\n",j,t[j]);
	}
}
int main()
{
	test();
	return 0;
}