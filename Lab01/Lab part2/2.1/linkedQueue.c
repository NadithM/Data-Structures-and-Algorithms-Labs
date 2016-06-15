#include <stdio.h>
#include <stdlib.h>

#define DATA_TYPE int
typedef struct node node;
typedef node** nodepp;

struct node{
DATA_TYPE data;
node * next;
node * pre;
};

typedef struct 
{
node * front;
node * head;
int size;
}queue_t;

typedef queue_t * QUEUE;


QUEUE queueCreate(){
 nodepp temp=malloc(sizeof(node *));
 *temp=NULL;
 QUEUE QueueObj=malloc(sizeof(queue_t));

 
 (QueueObj->front)=*temp;
 QueueObj->head=*temp;
 QueueObj->size=0;
	return QueueObj;
}

int queueDestroy(QUEUE QueueObj){
	node * head=(QueueObj->head);

	while(head!=NULL){
		head=(QueueObj->head)->next;
		free(QueueObj->head);
		(QueueObj->head)=head;
	}
	free(QueueObj);
	return 1;

}

int queueIsEmpty(QUEUE QueueObj){

	if((QueueObj->size)==0) return 1;


	return 0;
}


int enqueue(QUEUE QueueObj,DATA_TYPE data){

	node * temp=NULL;
	temp=malloc(sizeof(node));
	if(temp==NULL) return 0;
	temp->data=data;
	temp->next=(QueueObj->head);

	temp->pre=NULL;
	if(QueueObj->size>0)(QueueObj->head)->pre=temp;
	if(QueueObj->size==0)QueueObj->front=temp;
	QueueObj->head=temp;


	QueueObj->size++;
	//printf("i n enqueue head: %p \n ",QueueObj->head);
	//printf("i n enqueue front: %p \n ",QueueObj->front);
	//printf("i n enqueue  temp: %p \n ",temp);
	//printf("i n enqueue next : %p \n ",temp->next);
	//printf("i n enqueue pre : %p \n ",(QueueObj->head)->pre);
	return 1;
}

int dequeue(QUEUE QueueObj,DATA_TYPE * data){

	if( queueIsEmpty(QueueObj) )
	return 0;
	
		//printf(" Pop entered %p\n ",QueueObj->front);
	*data=(QueueObj->front)->data;
	
	node * temp=QueueObj->front;

	QueueObj->front=(QueueObj->front)->pre;

	QueueObj->size--;
	free(temp);

	
	return 1;
}


int queuePeek(QUEUE QueueObj,DATA_TYPE * data){

	if(queueIsEmpty(QueueObj))
		return 0;
 	*data=(QueueObj->front)->data;
	return 1;
}


int main(){


QUEUE  Queue = queueCreate();
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
for(i=5;i<9;i++){
 if(dequeue(Queue,&data))

 printf("dequeue  :%i\n",data);
 //printf("size :%i\n",Queue->size);
 
}



queueDestroy(Queue);

	return 0;
}
