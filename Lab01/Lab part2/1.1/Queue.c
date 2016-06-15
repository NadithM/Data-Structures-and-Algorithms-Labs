#include <stdio.h>
#include <stdlib.h>

#define DATA_TYPE int
typedef struct 
{
DATA_TYPE * queue;
int size;
DATA_TYPE * front;
DATA_TYPE * rear;

int slots;

}queue_t;
typedef queue_t  * QUEUE;
queue_t * queueCreate(int slots){

	DATA_TYPE * temp=malloc(sizeof(DATA_TYPE) * slots);
	queue_t * s1=malloc(sizeof(queue_t));
//	printf("created :%i\n",temp );
	s1->queue=temp;
	s1->size=0;
	s1->front=&temp[0]-1;
	s1->rear=&temp[0]-1;
//	printf("Pointed to first :%i\n",s1->rear );
//	printf("Pointed to last:   %i\n",&temp[slots-1] );
	s1->slots=slots;

	return s1;
}

int queueDestroy(queue_t * s1){
	
	free(s1->queue);
	free(s1);
	//printf("queue distroied \n" );

	return 1;
}

int queueIsEmpty(queue_t * s1){
		
	if(s1->size!=0) {
		
		return 0;
	}

	printf("queue empty\n" );
	return 1;
}

int queueIsFull(queue_t * s1){
	if( s1->size != s1->slots ) {

		return 0;
	}

	printf("queue full \n" );
	return 1;

}

int enqueue(queue_t * s1,DATA_TYPE data){

	if(queueIsFull(s1))
	return 0;

	if(		( (DATA_TYPE)(s1->rear)==( (DATA_TYPE)(s1->queue) + (s1->slots-1)*sizeof(DATA_TYPE) ) ) && ( s1->size != s1->slots ) ){

	//	printf("wrap the array before: %i\n",s1->rear );
		s1->rear=(DATA_TYPE *)s1->queue;
	//	printf("wrap the array after: %i\n",s1->rear );
	}
	else {
		s1->rear++;
	}
	
	*(s1->rear)=data;
//	printf("data entry %i\n",*(s1->rear) );
		s1->size++;

	return 1;
}

int  dequeue (queue_t * s1,DATA_TYPE  * data){

	if( queueIsEmpty(s1) )
	return 0;

	

	if(		 (DATA_TYPE)(s1->front)==( (DATA_TYPE)(s1->queue) + (s1->slots-1)*sizeof(DATA_TYPE) ) && s1->size !=0){

		s1->front=s1->queue;
	}

	else{

		s1->front++;
	}
	*data=*(s1->front);
	
		s1->size--;
	return 1;
}


int queuePeek(queue_t * s1,DATA_TYPE *data){

	if(queueIsEmpty(s1)){
			 *data=(DATA_TYPE)NULL;
			return 0;
	}

	if(		 (DATA_TYPE)(s1->front)==( (DATA_TYPE)(s1->queue) + (s1->slots-1)*sizeof(DATA_TYPE) ) && s1->size !=0){
		DATA_TYPE * tmp=s1->front;
		s1->front=s1->queue;
		*data=*(s1->front);
		s1->front=tmp;
	}

	else{

		s1->front++;
		*data=*(s1->front);
		s1->front--;
	}




	return 1;
}

int main(){


QUEUE  Queue = queueCreate(5);
int i=0,data=0;
for(i=3;i<5;i++){
 
 if(enqueue(Queue,i))
 	printf("enqueue  :%i\n",i);
}
dequeue(Queue,&data);
printf("dequeue :%i\n",data);
queuePeek(Queue,&data);
printf("Peek :%i\n",data);
dequeue(Queue,&data);
printf("dequeue  :%i\n",data);
queuePeek(Queue,&data);
printf("Peek :%i\n",data);


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


	return 0;
}