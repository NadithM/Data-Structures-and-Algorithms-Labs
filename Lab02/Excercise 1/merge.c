/* Merge sort in C */
#include <stdio.h>
#include <stdlib.h>

#define DT int


void merge(DT *Array, DT *LeftArray,int leftSize,DT *RightArray,int rightSize);
void mergeSort(DT *Array,int arraySize);



void merge(DT *Array, DT *LeftArray,int leftSize,DT *RightArray,int rightSize) {
	int i=0,j=0,k=0;

	while(i<leftSize && j< rightSize) {
		if(LeftArray[i]  < RightArray[j]) 
			Array[k++] = LeftArray[i++];
		else 
			Array[k++] = RightArray[j++];
	}
	while(i < leftSize) 
		Array[k++] = LeftArray[i++];
	while(j < rightSize) 
		Array[k++] = RightArray[j++];
}

void mergeSort(DT *Array,int arraySize) {
	int mid,x; 
	DT *LeftArray, *RightArray;
	if(arraySize < 2) return; 
	else{
		mid = arraySize/2;
		LeftArray = (DT *)malloc(mid*sizeof(DT)); 
		RightArray = (DT *)malloc((arraySize- mid)*sizeof(DT)); 
		
		for(x = 0;x<mid;x++) LeftArray[x] = Array[x]; 
		for(x = mid;x<arraySize;x++) RightArray[x-mid] = Array[x]; 

		mergeSort(LeftArray,mid); 
		mergeSort(RightArray,arraySize-mid);  
		merge(Array,LeftArray,mid,RightArray,arraySize-mid);  
	    free(LeftArray);
	    free(RightArray);


    }
}

