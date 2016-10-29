#ifndef _ws_stack
#define _ws_stack

/*
c stack demo.
winxos 2014-03-19 

usage:
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
*/


#include<assert.h> 
typedef struct
{
	int top;
	int *buf;
}cStack;
typedef cStack* STACK;
typedef enum {FALSE,TRUE}BOOL;

#define MAX_SIZE 100

STACK create_stack()
{
	STACK s=(STACK)malloc(sizeof(cStack));
	s->top=0;
	s->buf=(int*)malloc(sizeof(int)*MAX_SIZE);
	return s; 
}
void dispose_stack(STACK s)
{
	free(s->buf);
	free(s);
}
BOOL is_empty(STACK s)
{
	return (BOOL)(s->top<=0);
} 
BOOL is_full(STACK s)
{
	return (BOOL)(s->top>=MAX_SIZE);
} 
int size(STACK s)
{
	return s->top; 
}
//push data to s
void push(STACK s,int n)
{
	assert(is_full(s)==FALSE);
	s->buf[s->top++]=n;
}
//get and remove the top data
int pop(STACK s)
{
	assert(is_empty(s)==FALSE);
	return s->buf[--s->top];
}
//get the top data but not remove
int peek(STACK s)
{
	assert(is_empty(s)==FALSE);
	return s->buf[s->top-1];	
} 
#endif
