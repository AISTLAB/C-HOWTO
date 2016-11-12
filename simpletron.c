/*
simpletron c version.
for c fun.
winxos 2013-4-10 
*/
#include <stdio.h>
#include <stdlib.h>
enum{
    READ=10,WRITE,
    LOAD=20,STORE,
    ADD=30,SUB,MUL,DIV,
    JMP=40,JMPN,JMPZ,HALT
};

#define MAX_MEM 100

int MEMORY[MAX_MEM]= {0};
int instruction_count=0,accumulator=0;
int operator_code,operand;
void dump() //show memory 
{
	int i,j;
	printf("\n ");
	for(i=0;i<10;i++) printf("%5d",i+1);
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("%02d ",i);
		for(j=0;j<10;j++)
		{
			printf(" %04d",MEMORY[i*10+j]);
		}
		printf("\n");
	} 
}  
void input_code() //input the code
{
    int n=0,i=0;
    memset(MEMORY,0,MAX_MEM*sizeof(int));
    printf("\ninput machine code(-1 to end)\n");
    while(n>=0)
    {
    	printf("%02d? ",i);
    	scanf("%d",&n);
		if(n>=0) MEMORY[i++]=n;    	
    }
}
int run()
{
    instruction_count=0;
    while(instruction_count<MAX_MEM)
    {
        operator_code=MEMORY[instruction_count] / MAX_MEM;
        operand=MEMORY[instruction_count] % MAX_MEM;
        switch(operator_code)
        {
        case READ:scanf("%d", &MEMORY[operand]);break;
        case WRITE:printf("%d ",MEMORY[operand]);break;
        case LOAD:accumulator=MEMORY[operand];break;
        case STORE:MEMORY[operand]=accumulator;break;
        case ADD:accumulator+=MEMORY[operand];break;
        case SUB:accumulator-=MEMORY[operand];break;
        case MUL:accumulator*=MEMORY[operand];break;
        case DIV:accumulator/=MEMORY[operand];break;
        case JMP:instruction_count=operand-1;break;
        case JMPN:accumulator<0?instruction_count=operand-1:0;break;
        case JMPZ:accumulator==0?instruction_count=operand-1:0;break;
        case HALT:goto END;break;
        }
        instruction_count++;
    }
END:
    dump();
    return 0;
}
int main(int args, char ** argv)
{
	if(args>1)
	{
		FILE *fi;
		int i=0;
		if(fi=fopen(argv[1],"r"))
		{
			while(fscanf(fi,"%d",&MEMORY[i++])!=EOF);
		}
		run();
	}
	else
	{
		while(1)
		{
	 		input_code();
	 		run();  
	  	}  		
	}
    return 0;
}
