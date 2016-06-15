#include <stdio.h>
#include <stdlib.h>

#define DATA_TYP  int

typedef struct 
{
DATA_TYP * stack;
int index;
int cap;

}stack_t;

typedef  stack_t*  STACK;

STACK stackCreate(int cap);
int stackDestroy(STACK s1);
int StackIsEmpty(STACK s1);
int StackIsFull(STACK s1);
int stackPush(STACK s1,DATA_TYP data);
int stackPop(STACK s1,DATA_TYP  * data);
int stackPeek(STACK s1,DATA_TYP *data);




STACK stackCreate(int cap){
	DATA_TYP * temp=malloc(sizeof(DATA_TYP)* cap);
	stack_t * s1=malloc(sizeof(stack_t));

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

	if(s1->index==0) return 1;


	return 0;
}

int StackIsFull(STACK s1){
	if( s1->cap == s1->index ) return 1;
	return 0;
}

int stackPush(STACK s1,DATA_TYP data){

	if(StackIsFull(s1))
	return 0;
	
	s1->stack[s1->index]=data;
	s1->index++;
	return 1;
}

int stackPop(STACK s1,DATA_TYP  * data){

	if( StackIsEmpty(s1) )
	return 0;

	s1->index--;
	*data= (s1->stack[s1->index]);
	return 1;
}


int stackPeek(STACK s1,DATA_TYP *data){

	if(StackIsEmpty(s1))
		return 0;
 	*data= s1 -> stack[ s1->index-1];
	return 1;
}


