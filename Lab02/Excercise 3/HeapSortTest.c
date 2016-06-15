#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "max_heap.h"

#define ARRAY_SIZE 10
#define RANGE 10000

void DisplayArray(int * Array){
	int i=0;
	for(i=0;i<ARRAY_SIZE;i++)
		printf("%4d,",Array[i]);
	
}

void InitializeArray(int * Array){
	int i=0;
	time_t t;
    srand((unsigned) time(&t));

	for(i=0;i<ARRAY_SIZE;i++){
		Array[i]=rand() % RANGE;
	}
}


int main(){


int array[ARRAY_SIZE]={};
int i=0;
float seconds;
clock_t end ,start;

InitializeArray(array);
printf("Unsorted array\n\n");
DisplayArray(array);

HEAP heap = heapify(array,ARRAY_SIZE);

//for(i=0;i<ARRAY_SIZE;i++){printf("%d at %d \t",heap->hArray[i],i+1); }

start = clock();


HeapSort(heap,array);


end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;

//printf("\n\n");
printf("\nSorted array\n\n");
DisplayArray(array);
printf("\n\nTime taken for sort= %f sec\n",seconds);

return 0;
	
}



