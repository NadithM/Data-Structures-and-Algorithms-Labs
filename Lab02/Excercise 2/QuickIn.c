#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DT int
#define RANGE 10000
#define ARRAY_SIZE 10000
#define THRESHOLD 1000

int  insertSortflag=1;


void swap(DT *var1, DT *var2) {
	DT temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

void choosePivot(DT *Array, int first, int last) {
	int mid = (first + last) / 2;

	if ( (Array[first] < Array[last]) && (Array[first] < Array[mid] && Array[mid] < Array[last])  ) 
		swap(&Array[first], &Array[mid]);
		
	else {
		if (Array[last] < Array[mid] && Array[mid] < Array[first])
			swap(&Array[first], &Array[mid]);
		else
			swap(&Array[first], &Array[last]);
	}
}

void partition(DT *Array, int first, int last, DT *pivot) {
	choosePivot(Array, first, last);

	*pivot = Array[first];

	int last_sort = first;
	int unknown = first + 1;

	for (; unknown <= last; unknown++) {
		if (Array[unknown] < *pivot) {
			last_sort++;
			swap(&Array[unknown], &Array[last_sort]);
		}
	}

	swap(&Array[first], &Array[last_sort]);
	*pivot = last_sort;
}

void insertionSort(DT * arr, int n)
{
   int i, key, j;
  // printf("\t\t::::::::::::::::         Sorted Using Insertion            :::::::::::::::::::\n\n");
		
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void quickSort(DT *Array, int first, int last,int threshold) {

	if(insertSortflag && (threshold >= last+1 ) ){
		insertionSort(Array,last+1);
		return;
	}

	insertSortflag=0;

	int pivot_index;
		
	if (first < last) {
		partition(Array, first, last, &pivot_index);
		quickSort(Array, first, pivot_index - 1,threshold);
		quickSort(Array, pivot_index + 1, last,threshold);
		
	}	
	
}

void quickInSort(DT *Array, int first, int last,int threshold){

	quickSort(Array,first,last,threshold);
	insertSortflag=1;
}

void DisplayArray(DT * Array){
	int i=0;
	for(i=0;i<ARRAY_SIZE;i++)
		printf("%4d,",Array[i]);
	
}

void InitializeArray(DT * Array){
	int i=0;
	time_t t;
    srand((unsigned) time(&t));

	for(i=0;i<ARRAY_SIZE;i++){
		Array[i]=rand() % RANGE;
	}
}



int main() {

	int Array[ARRAY_SIZE] ={};


	
	int j=0,k=1;
	int noElements;
	float seconds[30]={};
	clock_t end ,start;

while(j<30){

	InitializeArray(Array);
	//printf("\t\t::::::::::::::::Unsorted array:::::::::::::::::::\n\n");
	
	//DisplayArray(Array);	

	int last = sizeof(Array)/sizeof(Array[0])-1; 

	start = clock();

	//printf("Threshold = %d \n",threshold);
	quickInSort(Array, 0, last,THRESHOLD);

	end = clock();
	seconds[j] = (float)(end - start) / CLOCKS_PER_SEC;

	
	//printf("\t\t::::::::::::::::Sorted array:::::::::::::::::::\n\n");

	//DisplayArray(Array);


	printf("Time taken %d : run = %f\n",j,seconds[j]);
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