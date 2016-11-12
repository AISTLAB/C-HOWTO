#include <stdio.h>
#define MAX_MEM 256
#define COLS 16
#define TITLE_FORMAT "%6X"
#define DATA_FORMAT "%6d"
#define COL_HEADER_FORMAT "\n%3d"

int MEM[MAX_MEM] = { 0 };

void dump() //Pretty Show Memory For Debugging 
{
	int i;
	printf("\nMEMORY:\n%3s", "");
	for (i = 0; i < COLS; i++)
	{
		printf(TITLE_FORMAT, i);
	}
	for (i = 0; i < MAX_MEM; i++)
	{
		if (i % COLS == 0)
		{
			printf(COL_HEADER_FORMAT, i / COLS);
		}
		printf(DATA_FORMAT, MEM[i]);
	}
	puts("\n");
}
void dump2(int index)//using recursive function
{
	if (index == MAX_MEM)
		return;
	if (index == 0)
	{
		printf("\nMEMORY:\n%3s", "");
		for (int i = 0; i < COLS; i++)
		{
			printf(TITLE_FORMAT, i);
		}
	}
	if (index % COLS == 0)
	{
		printf(COL_HEADER_FORMAT, index / COLS);
	}
	printf(DATA_FORMAT, MEM[index]);
	dump2(index + 1);
}
int main()
{
	dump();
	dump2(0);
	return 0;
}