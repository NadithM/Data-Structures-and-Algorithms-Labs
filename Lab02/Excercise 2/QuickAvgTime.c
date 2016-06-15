#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Quick.h"


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
	int Array[ARRAY_SIZE] ={};
	int j=0;
	int noElements;
	float seconds[30]={};
	clock_t end ,start;
	printf("\nSorting a %d Elements of Integers.following are the time in Each Trials\n",ARRAY_SIZE);

while(j<30){

	InitializeArray(Array);

	//	printf("\t\t::::::::::::::::Unsorted array:::::::::::::::::::\n\n");
	//DisplayArray(Array);

	int last = sizeof(Array)/sizeof(Array[0])-1; 

	start = clock();

	quickSort(Array, 0, last);

	end = clock();
	seconds[j] = (float)(end - start) / CLOCKS_PER_SEC;

	
	//printf("\t\t::::::::::::::::Sorted array:::::::::::::::::::\n\n");
	//DisplayArray(Array);

	printf("Time taken %d : run = %f\n",j,seconds[j]);
	j++;
	
	}
	int i=0;
	float avgsum=0;
	for(i=0;i<30;i++){
		avgsum += seconds[i];
	}

	float avg=avgsum/30;
	printf("avg Time taken for 30 runs = %f\n",avg);

	return 0;
}