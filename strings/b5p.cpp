#include <iostream>
using namespace std;
char tb[70][20];
void show()
{
	int i,j;
	char s[1500];
	for(i=0;i<20;i++)
	{
		for(j=0;j<70;j++)
		{
			if(tb[j][i]==0)sprintf(s,"%s ",s);
			else if(tb[j][i]==1)sprintf(s,"%s@",s);
			else if(tb[j][i]==2)sprintf(s,"%s$",s);
			else sprintf(s,"%s*",s);
		}
		sprintf(s,"%s\n",s);
	}
	printf("%s",s);
}
void run(int x)
{
	int i,j;
	srand(x);
	for(i=0;i<20;i++)
	{
		for(j=0;j<70;j++)
		{
			tb[j][i]=rand()%5;
		}
	}
}
void run2(int x)
{
	int i;
	if(x%150>80)
	{
		tb[x%70][10]=0;
	}
	else
	{
		for(i=0;i<x;i++)
		{
			tb[i][10]=1;
		}
	}
}
int main()
{
	int i=0;
	while(1)
	{
		run(i);
		run2(i);
		show();
		system("ping -n 1 127.1>nul");
		system("cls");
		i++;
		if(i>150)i=0
	}
	return 0;
}