#include<stdio.h>
#include"stack.h"
int main(void)
{
	STACK a;
	a=create_stack();
	push(a,10);
	push(a,11);
	push(a,13);
	push(a,15);
	printf("%d\n",size(a));
	printf("%d\n",peek(a));
	printf("%d\n",pop(a));
	printf("%d\n",pop(a));
	dispose_stack(a);
	printf("good.");
	return 0;	
} 
