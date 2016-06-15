/* Merge sort in C */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"


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

	printf("\nSorting %d Elemetns using merge Sort\n\n",ARRAY_SIZE);
	int Array[ARRAY_SIZE] ;

	InitializeArray(Array);
	

	printf("\t\t::::::::::::::::Unsorted array:::::::::::::::::::\n\n");
	
	DisplayArray(Array);

	printf("\n\n" );

	int noElements;

	noElements = sizeof(Array)/sizeof(Array[0]); 
	clock_t start = clock();

	mergeSort(Array,noElements);


	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	
	printf("\t\t::::::::::::::::Sorted array:::::::::::::::::::\n\n");
	
	DisplayArray(Array);


	printf("\n\n\t\t::::::::::::::::Time taken - %f sec:::::::::::::::::::\n\n",seconds);
	

	
		

	return 0;
}