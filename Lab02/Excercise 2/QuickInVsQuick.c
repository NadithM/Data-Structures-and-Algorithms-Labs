#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QuickIn.h"


#define RANGE 10000

//Simply changing the value of the SIZE  & Trials run the programe 
//several time we can Identify the best threshold using the result
 
#define SIZE 1000
#define TRIALS 50

void DisplayArray(DT * Array,int size){
	int i=0;
	for(i=0;i<size;i++)
		printf("%4d,",Array[i]);

	printf("\n\n");	
}

void InitializeArray(DT * Array,int size){
	int i=0;
	time_t t;
    srand((unsigned) time(&t));

	for(i=0;i<size;i++){
		Array[i]=rand() % RANGE;
	}
}

void CopyArray(DT * ArrayA,DT *ArrayB ,int size){
	int i=0;

	for(i=0;i<size;i++){
		ArrayB[i]=ArrayA[i];
	}
}



int main() {

	
	
	int threshold=SIZE+5;

	int Array1[SIZE] ={};
	int Array2[SIZE] ={};
	

	
	int j=0;
	int noElements;
	float secondsI[TRIALS]={};
	float secondsQ[TRIALS]={};
	clock_t end ,start;

while(j<TRIALS){

	InitializeArray(Array1,SIZE);
	CopyArray(Array1,Array2,SIZE);
	//printf("Unsorted array\n\n");
	//DisplayArray(Array1,SIZE);	
	//DisplayArray(Array2,SIZE);
	int last = sizeof(Array1)/sizeof(Array1[0])-1; 

	if(j==0)printf("Threshold = %d \n",threshold);
	start = clock();
	//quickSort(Array, 0, last);
	quickInSort(Array1, 0, last,threshold);

	end = clock();
	secondsI[j] = (float)(end - start) / CLOCKS_PER_SEC;



	last = sizeof(Array2)/sizeof(Array2[0])-1; 
	threshold=threshold-10;
	start = clock();

	quickInSort(Array2, 0, last,threshold);

	end = clock();
	secondsQ[j] = (float)(end - start) / CLOCKS_PER_SEC;

	
	//printf("Sorted array\n\n");
	//DisplayArray(Array1,SIZE);
	//DisplayArray(Array2,SIZE);


	//printf("\n\n");
	j++;
	
	}

	float avgsumI=0;
	float avgsumQ=0;
	int i;
	for(i=0;i<TRIALS;i++){
		avgsumI += secondsI[i];
	}
	for(i=0;i<TRIALS;i++){
		avgsumQ += secondsQ[i];
	}

	float avgI=avgsumI/TRIALS;
	float avgQ=avgsumQ/TRIALS;
	printf("using QuickInSort algo with bigger threshold than size Avg Time taken for %d runs = %f sec\n",TRIALS,avgI);
	printf("using QuickInSort algo with lower threshold than size(without Insertion sort) Avg Time taken for %d runs = %f sec\n",TRIALS,avgQ);
	


	
	

	return 0;
}