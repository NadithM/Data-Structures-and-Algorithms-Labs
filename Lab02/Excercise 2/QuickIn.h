#include <stdio.h>
#include <stdlib.h>


#define DT int

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
	//printf("\tIS");
	quickSort(Array,first,last,threshold);
	insertSortflag=1;
}

