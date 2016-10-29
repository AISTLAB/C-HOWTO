#include <stdio.h>
#include <string.h> //memset
#include <stdlib.h> //system
#include <math.h>
#define MX 70
#define MY 20
char tb[MX][MY];
void show()
{
	int i,j;
	char s[MX*MY+1]={0};
	for(i=0;i<MY;i++)
	{
		for(j=0;j<MX;j++)
		{
			if(tb[j][i]==0)sprintf(s,"%s ",s);
			else if(tb[j][i]==1)sprintf(s,"%s|",s);
			else if(tb[j][i]==2)sprintf(s,"%s-",s);
			else if(tb[j][i]==3)sprintf(s,"%so",s);
			else sprintf(s,"%s*",s);
		}
		sprintf(s,"%s\n",s);
	}
	printf("%s",s);
}
void run(int x)
{
	int i;
	memset(tb,0,MX*MY*sizeof(char));
	for(i=0;i<MY;i++)tb[MX/2][i]=1;
	for(i=0;i<MX;i++)tb[i][MY/2]=2;
	for(i=5;i<65;i++)
	{
		tb[i][(int)(sin((i+x)/10.0)*8+10)]=3;
	}
	for(i=5;i<65;i++)
	{
		tb[i][(int)(cos((i+x)/5.0)*5+10)]=4;
	}
}
int main()
{
	int i=0;
	while(1)
	{
		system("cls");
		run(i);
		show();
		_sleep(10); //延时10ms，根据编译器具体情况要适当修改
		i++;
	}
	return 0;
}