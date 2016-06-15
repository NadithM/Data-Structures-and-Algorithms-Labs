#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "max_heap.h"

#define ARRAY_SIZE 1000000
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
int i=0,j=0;
float seconds[30]={};
clock_t end ,start;

printf("\nSorting a %d Elements of Integers using HeapSort.following are the time in Each Trial\n",ARRAY_SIZE);


while(j<30){
	InitializeArray(array);
	//DisplayArray(array);
	HEAP heap = heapify(array,ARRAY_SIZE);

	start = clock();
	HeapSort(heap,array);
	end = clock();

	seconds[j] = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Time taken %d : run = %f\n",j,seconds[j]);
	j++;
	heapDestroy(heap);

}

	float avgsum=0;

	for(i=0;i<30;i++){
		avgsum += seconds[i];
	}

	float avg=avgsum/30;
	printf("avg Time taken for 30 runs = %f\n",avg);


printf("\n\n");
//DisplayArray(array);
return 0;
	
}



