#include <stdio.h>
#include <stdlib.h>

#define DT int

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
	int unknown;

	for (unknown = first + 1; unknown <= last; unknown++) {
		if (Array[unknown] < *pivot) {
			last_sort++;
			swap(&Array[unknown], &Array[last_sort]);
		}
	}

	swap(&Array[first], &Array[last_sort]);
	*pivot = last_sort;
}

void quickSort(DT *Array, int first, int last) {
	int indexOfPivot;
	
	if (first < last) {
		partition(Array, first, last, &indexOfPivot);
		quickSort(Array, first, indexOfPivot - 1);
		quickSort(Array, indexOfPivot + 1, last);
	}
}

