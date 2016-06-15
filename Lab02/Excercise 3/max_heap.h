#include <stdio.h>
#include <stdlib.h>


#define DATA_TYPE int

typedef struct 
{
DATA_TYPE * hArray;
int head;
int size;

}heap_t;

typedef heap_t * HEAP;

HEAP heapCreate(int cap){
	DATA_TYPE * temp=malloc(sizeof(DATA_TYPE)*(cap+1) );
	HEAP h1=malloc(sizeof(heap_t));

	h1->hArray=temp;
	h1->head=1;
	h1->size=0;

	return h1;
}

void heapDestroy(HEAP h1){
	
	free(h1->hArray);
	free(h1);

}

void heapShiftUp (HEAP h1, int child){
	//printf("goto chid : %d\t",child );
int temp;
    if(child>1){
        if( (h1->hArray[child]) > (h1->hArray[child/2]) ){

            temp= h1->hArray[child];
            h1->hArray[child] = h1->hArray[child/2];
            h1->hArray[child/2] = temp;
            heapShiftUp (h1,child/2);    
        }
    }
        else if(child==0){


        	//printf("index become outof bound: \n");
        }
    

}

void heapInsert (HEAP h1,DATA_TYPE data){

	int nextindex=h1->head;
	//printf("nextindex: %d\t",nextindex );

	h1->hArray[nextindex]=data;

	heapShiftUp(h1,nextindex);

	h1->head++;
	h1->size++;
	//printf("head : %d size : %d\n",h1->head,h1->size );

}

void heapShiftDown (HEAP h1, int parent){
	int temp;
	//printf("goto index parent : %d \n",parent  );
if(  ( (2*parent)+1 ) < (h1->head)   ){

    
if( ( (h1->hArray[2* parent]) < (h1->hArray[(2*parent)+1]) )    ){

	if( ( (h1->hArray[parent]) < (h1->hArray[(2*parent)+1]) ) ){
    	
   	 	temp= h1->hArray[(2*parent)+1];
        h1->hArray[(2*parent)+1] = h1->hArray[parent];
        h1->hArray[parent] = temp;
       //printf("goto index parent : %d swap data %d at the movement head %d \n",parent,h1->hArray[2*parent+1], h1->head  );
    
        heapShiftDown(h1,(2*parent)+1);
    }


}

else {

 if(( (h1->hArray[parent])  < (h1->hArray[2*parent]) ) && ( (2 * parent)< (h1->head)) ){
    	//printf("else goto index parent : %d swap data %d at the movement head %d \n",parent,h1->hArray[2*parent], h1->head  );
   
   	 	temp= h1->hArray[2*parent];
        h1->hArray[2*parent] = h1->hArray[parent];
        h1->hArray[parent] = temp;
        heapShiftDown(h1,2*parent);
    }

}
}



}

int heapRemove (HEAP h1,int * data){
//printf("size : %d\n",h1->size );
if( h1->size!=0 ){
	*data=h1->hArray[1];


	h1->hArray[1]=h1->hArray[h1->head-1];
	//printf("get data %d at index %d to root :\n",h1->hArray[h1->head-1],h1->head-1);
	h1->head--;
	h1->size--;
	
}
	
else
	return 0;

	heapShiftDown(h1,1);
	//printf("goto index paren" );
   


}



HEAP heapify(DATA_TYPE * array,int size){
int i=0;
HEAP temp1=heapCreate(size);
//printf("size of the array :%d\n",size );
while(i<size){

heapInsert(temp1,array[i]);
i++;
}
//for(i=1;i<=ARRAY_SIZE;i++) printf("%d\n",temp1->hArray[i] );
//for(i=0;i<ARRAY_SIZE;i++)heapRemove(temp1,&array[i]);
//DisplayArray(array);
//printf("out of funtion\n");
return temp1;


}



void HeapSort(HEAP h1,int *array){

int i=0;
int si=h1->size;
for(i=0;i<si;i++)heapRemove(h1,&array[si-1-i]);
}





