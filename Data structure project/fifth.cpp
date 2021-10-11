#include "fifth.h"
#include "selection.h"
double fifth::fifthSort(double arr[], int size, int index) {
	int  numArrays, precision, row;
	double*insideMedian;
	if (size <= 5) {
		bubbleSort(arr, size);
		return arr[index - 1];
	}
	else {
		precision = size % 5;
		numArrays = size / 5;
		for (int i = 0; i < numArrays; i++) {
			bubbleSort(arr + i * 5, 5);
		}
		if (precision != 0) {
			bubbleSort(arr + ((numArrays++) * 5), precision);
		}
		insideMedian = new double[numArrays];
	}for (int j = 1; j <= numArrays; j++) {
		insideMedian[j - 1] = arr[(j - 1) * 5 + 2];
	}
	if (precision != 0) {
		if (precision % 2 != 0) {
			insideMedian[numArrays - 1] = arr[((numArrays - 1) * 5) + ((precision / 2))];
		}
		else {
			insideMedian[numArrays - 1] = arr[(((numArrays - 1) * 5) + ((precision / 2))) - (1)];
		}
	}
	double pivot1Val = fifthSort(insideMedian, numArrays, numArrays / 2);
	int resIndex = findIndex(arr, size, pivot1Val);
	swap(arr[0], arr[resIndex]);
	int k = selection::partition(arr, 0, size - 1);
	if (k > index) {
		return fifthSort(arr, k, index);
	}
	else if (k < index) {
		return fifthSort(arr + k + 1, size - (k + 1), index - (k + 1));
	}
	else {
		return arr[k - 1];
	}
	delete[] insideMedian;
}
void fifth::mySwap(double & a, double & b){
	double t = a;
	a = b;
	b = t;
}
void fifth::bubbleSort(double arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				mySwap(arr[j], arr[j + 1]);
}
int fifth::findIndex(double * arr, int size, double val) {
	int res;
	for (res = 0; res < size; res++) {
		if (arr[res] == val) {
			return res;
		}
	}
	return 0;
}


