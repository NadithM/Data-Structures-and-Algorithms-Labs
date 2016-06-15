#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

typedef struct
{
	STACK s1;
	STACK s2;

}queue_t;

#define DATA_TYPE int

typedef queue_t * QUEUE;
queue_t * queueCreate(int slots){

	queue_t * queue=malloc(sizeof(queue_t));

	STACK stack1=stackCreate(slots);
	STACK stack2=stackCreate(slots);
	(queue->s1)=stack1;
	(queue->s2)=stack2;

	return queue;
}

int queueDestroy(queue_t * queue){
	
	stackDestroy((queue->s1));
	stackDestroy((queue->s2));
	
	return 1;
}

int queueIsEmpty(queue_t * queue){
		
	StackIsEmpty((queue->s1));
	printf("queue empty\n" );
	return 1;
}

int queueIsFull(queue_t * queue){
	StackIsFull((queue->s1));

	printf("queue full \n" );
	return 1;

}

int enqueue(queue_t * queue,DATA_TYPE data){

	if(StackIsFull((queue->s1)))
	return 0;

	stackPush((queue->s1),data);
	
	return 1;
}

int  dequeue (queue_t * queue,DATA_TYPE  * data){

	if( StackIsEmpty((queue->s1)) && StackIsEmpty((queue->s2)) )
	return 0;

	if(StackIsEmpty((queue->s2))){
		DATA_TYPE tempdata;
		while(stackPop((queue->s1),&tempdata))
			stackPush((queue->s2),tempdata);
	}

	stackPop((queue->s2),data);
	return 1;
}


int queuePeek(queue_t * queue,DATA_TYPE *data){

	if( StackIsEmpty((queue->s1)) && StackIsEmpty((queue->s2)) )
	return 0;

	DATA_TYPE tempdata;
	if(StackIsEmpty((queue->s2)) ){
		
		while(stackPop((queue->s1),&tempdata))
			stackPush((queue->s2),tempdata);
	}

	stackPeek((queue->s2),data);
	

	return 1;
}

STACK queueToStack(queue_t * queue){

STACK stack=stackCreate(queue->s1->cap);
int i=0;
int in=(queue->s1->index)-1;
DATA_TYPE data[queue->s1->cap];
while(dequeue(queue,&data[i])){
i++;
}

while(stackPush(stack,data[in])){
in--;
if(in==-1) break;
}
	return stack;
}


int main(){

QUEUE  Queue = queueCreate(5);


int i=0,data=2;
for(i=1;i<4;i++){
 
 if(enqueue(Queue,i))
 	printf("enqueue  :%i\n",i);
 //printf("fghfhf %i\n",Queue->s1->index );

}
STACK stack3=queueToStack(Queue);



dequeue(Queue,&data);
printf("dequeue :%i\n",data);//3
//printf("thrth %i\n",Queue->s1->index );
queuePeek(Queue,&data);
printf("Peek :%i\n",data);//4
queuePeek(Queue,&data);
printf("Peek :%i\n",data);//4
queuePeek(Queue,&data);
printf("Peek :%i\n",data);//4
dequeue(Queue,&data);
printf("dequeue :%i\n",data);//3

for(i=5;i<11;i++){
 
 if(enqueue(Queue,i))
 	printf("enqueue  :%i\n",i);
}

queuePeek(Queue,&data);
printf("Peek :%i\n",data);
for(i=5;i<11;i++){
 if(dequeue(Queue,&data))

 	printf("dequeue  :%i\n",data);
}

queueDestroy(Queue);

while(stackPop(stack3,&data)){
	printf("queue to stack elements :%i\n",data);
	
}


}