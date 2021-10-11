#pragma once
#include <iostream>
using namespace std;
class selection {
	public:
	static double selectionSort(double arr[], int left, int right, int index);
	static int partition(double arr[], int left, int right);
};