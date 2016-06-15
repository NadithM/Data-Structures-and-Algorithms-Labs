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





