#include "selection.h"
int selection::partition(double arr[], int left, int right) {
	double pivot = arr[left];
	while (left != right) {
		if (arr[left] > arr[right]) {
			swap(arr[left], arr[right]);
		}
		if (pivot == arr[left])
			right--;
		else
			left++;
	}
	return left;
}
double selection::selectionSort(double arr[], int left, int right, int index) {
	int pivot;
	int leftPart;
	pivot = partition(arr, left, right);
	leftPart = pivot - left + 1;
	if (index == leftPart)
		return arr[pivot];
	if (index < leftPart)
		return selectionSort(arr, left, pivot - 1, index);
	else
		return selectionSort(arr, pivot + 1, right, index - leftPart);
}
