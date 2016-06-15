#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 80
#define DATA_TYPE int

int stack_size=MEMORY_SIZE / sizeof(DATA_TYPE);
DATA_TYPE * stacksHouse=NULL;
int indexB=0;
int indexA=0;
int * StackB=&indexB;
int  * StackA=&indexA;



void stackCreate(){

stacksHouse=malloc(stack_size * sizeof(DATA_TYPE));
int i;
printf("hjhjhj %i\n",stack_size );
//for(i=0;i=stack_size ;i++) stacksHouse[i]='\0';
}

void stackDestroy(DATA_TYPE * satck){
 free(stacksHouse);
}

int StackIsEmpty(int * x){

	if((*x)== 0) {printf("Stack Is Empty.\n"); return 1;}

	return 0;
}

int StackIsFull(){
	if((indexA+indexB)==stack_size){printf("Stack Memory Is Full.\n"); return 1;}

	return 0;
}

int stackPush(int * Stack,DATA_TYPE data){

	if(StackIsFull())
	return 0;
	if(Stack == &indexA){
		stacksHouse[indexA]=data;
		indexA++;
	}

	else if(Stack == &indexB){
		stacksHouse[stack_size-1-indexB]=data;
		indexB++;

	}
	
	return 1;
}

int stackPop(int *stack,DATA_TYPE  * data){

	if( StackIsEmpty(stack) )
	return 0;

	if(stack == &indexA){
		indexA--;
		*data=stacksHouse[indexA];
		
	}

	else{
		indexB--;
		*data=stacksHouse[stack_size-1-indexB];
		

	}
	
	return 1;
}


int stackPeek(int * stack,DATA_TYPE *data){

	if(StackIsEmpty(stack))
		return -1;
 	if(stack == &indexA){
		*data=stacksHouse[indexA-1];	
	}

	else if(stack == &indexB){
		*data=stacksHouse[stack_size+1-indexB-1];
	}
	return 0;
}

int main(){

//stackhouse is created with limited memory
stackCreate();


int i,temp=0;
//elements are pushed to stacks from the front and end
//here when i=11 Stackhouse is full.So Messages show that front and end stack are full.

for(i=0;i<13;i++){
	if(stackPush(StackA,i))
		printf("pushed %i to stackA\n",i );
	
	if(i == 10 || i== 9 || i== 8){
		if(stackPush(StackA,++i))
			printf("pushed %i to stackA\n",i );
	}
}

for(i=0;i<8;i++){
		if(stackPush(StackB,20-i))
			printf("pushed %i to stackB\n",20-i );
	}
	

//check the peek
stackPeek(StackA,&temp);
printf("\n\nPeek from  front : %i\n",temp);
stackPeek(StackB,&temp);
printf("Peek from  end : %i\n\n",temp);

//print the stacks using stackPop

while(stackPop(StackA,&temp))
	printf("Pop from  front : %i\n",temp);

while(stackPop(StackB,&temp))
	printf("Pop from  end : %i\n",temp);





}