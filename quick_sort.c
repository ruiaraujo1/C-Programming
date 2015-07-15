#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void switch_values(int *x, int *y) {
	int tmp;
	
	tmp = *x;
	*x = *y;
	*y = tmp;
}


//it will be used the first element of the array and then "dragged" for the right position
int choose_pivot(int *vec, int begin, int end) {
	int i, pivot = begin;
	
	for (i = begin + 1; i <= end; i++) {
		// elements separation (left - lower than the pivot, right - bigger than the pivot
		if(vec[i] < vec[begin]) {
			pivot++;
			switch_values(&vec[i], &vec[pivot]);
		}
	}
	
	//stores in the pivot position the first element of the array
	switch_values(&vec[begin], &vec[pivot]);
	
	return pivot;
}


void quickSort(int *vec, int begin, int end) {
	int pivot;
	
	/* begin = end -> vetor ordenado */
	if(begin < end) {
		pivot = choose_pivot(vec, begin, end);
			
		quickSort(vec, begin, pivot - 1); 	//left sub-array
		
		quickSort(vec, pivot + 1, end); 	//right sub-array
	}
}

void printArray(int *vec, int size) {
	
	int i;
	
	for(i = 0; i < size; i++) {
		printf (" %d", vec[i]);
	}
}

int main() {
	int vec[SIZE] = {26, 13, 44, 8, 17, 89, 88, 99, 10, 6};
	
	printf("\nOriginal Array:");
	printArray(vec, SIZE);

	quickSort(vec, 0, SIZE - 1);
		
	printf("\nSorted Array:");
	printArray(vec, SIZE);
	
	
	return 0;
}
