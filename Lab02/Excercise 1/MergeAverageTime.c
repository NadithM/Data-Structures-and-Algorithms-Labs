/* Merge sort in C */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"


#define RANGE 10000
#define ARRAY_SIZE 1000000


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

	int Array[ARRAY_SIZE] ;
	int j=0;
	int myInt;
	int noElements;
	float seconds[30]={};
	clock_t end ,start;
	
	printf("\nSorting %d Elemetns using merge Sort\n\n",ARRAY_SIZE);
	
	while(j<30){


		InitializeArray(Array);
		
		//printf("\t\t::::::::::::::::Unsorted array:::::::::::::::::::\n\n");
		//DisplayArray(Array);

		noElements = sizeof(Array)/sizeof(Array[0]); 
		start = clock();

		mergeSort(Array,noElements);

		end = clock();
		seconds[j] = (float)(end - start) / CLOCKS_PER_SEC;

		//printf("\t\t::::::::::::::::Sorted array:::::::::::::::::::\n\n");
		//DisplayArray(Array);


		
		printf("Time taken %d : run = %f sec\n",j,seconds[j]);
		j++;
		
	}

	float avgsum=0;
	int i;
	for(i=0;i<30;i++){
		avgsum += seconds[i];
	}

	float avg=avgsum/30;
	printf("avg Time taken for 30 runs = %f\n",avg);
		

	return 0;
}