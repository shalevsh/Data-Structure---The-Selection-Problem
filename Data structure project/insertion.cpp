#include "insertion.h"
double Insertion::insertionSort(double arr[], int size, int index) {
	int i, j;
	for (i = 1; i < size; i++) {
		for (j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			double temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
	}
	return arr[index - 1];
}

