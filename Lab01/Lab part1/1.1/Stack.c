#include <stdio.h>
#include <stdlib.h>

#define DATA_TYPE char
typedef struct 
{
DATA_TYPE * stack;
int index;
int cap;

}stack_t;

typedef stack_t * STACK;

STACK stackCreate(int cap){
	DATA_TYPE * temp=malloc(sizeof(DATA_TYPE)* cap);
	STACK s1=malloc(sizeof(stack_t));

	s1->stack=temp;
	s1->index=0;
	s1->cap=cap;

	return s1;
}

int stackDestroy(STACK s1){
	
	free(s1->stack);
	free(s1);

	return 0;
}

int StackIsEmpty(STACK s1){

	if(s1->index!=0) return 0;


	return 1;
}

int StackIsFull(STACK s1){
	if( s1->cap != s1->index ) return 0;
	return 1;
}

int stackPush(STACK s1,DATA_TYPE data){

	if(StackIsFull(s1))
	return 0;
	
	s1->stack[s1->index]=data;
	s1->index++;
	return 1;
}

int stackPop(STACK s1,DATA_TYPE  * data){

	if( StackIsEmpty(s1) )
	return 0;

	s1->index--;
	*data= (s1->stack[s1->index]);
	
	return 1;
}


int stackPeek(STACK s1,DATA_TYPE *data){

	if(StackIsEmpty(s1))
		return 0;
 	*data= s1 -> stack[ s1->index-1];
	return 1;
}

int main(){


STACK  Stack = stackCreate(100);
char data='a';

if(stackPush(Stack,data))
	printf(" push %c\n",data);
data='b';
stackPush(Stack,data);
printf(" push %c\n",data);
data='c';
stackPush(Stack,data);
printf(" push %c\n",data);
data='d';
stackPush(Stack,data);
printf(" push %c\n",data);

if(stackPeek(Stack,&data))
	printf(" peek %c\n",data);

if(stackPop(Stack,&data))
	printf(" pop %c\n",data);

stackPop(Stack,&data);

printf(" pop %c\n",data);

stackPop(Stack,&data);

printf(" pop %c\n",data);

stackDestroy(Stack);


	return 0;
}