#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Quick.h"

#define RANGE 10000
#define ARRAY_SIZE 100

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


int main() {

	
	int Array[ARRAY_SIZE] ={};
	int j=0;
	int noElements;
	float seconds;
	clock_t end ,start;

	InitializeArray(Array);
	printf("\nSorting a %d Elements of Integers\n",ARRAY_SIZE);

	printf("Unsorted array\n\n");
	DisplayArray(Array);

	int last = sizeof(Array)/sizeof(Array[0])-1; 

	start = clock();

	quickSort(Array, 0, last);

	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;

	
	printf("\nSorted array\n\n");
	DisplayArray(Array);

	printf("\n\nTime taken %d : run = %f sec\n",j,seconds);
	
	
	



	return 0;
}