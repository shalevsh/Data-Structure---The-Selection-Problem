#include <iomanip>
#include <chrono>
#include <fstream>
#include "input.h"
#include "insertion.h"
#include "selection.h"
#include "fifth.h"

using namespace std;



int main(void) {
	int size, i = 0, index;
	double currNum = 0, *arr = nullptr, *insertArr = nullptr, *selectArr = nullptr, *fifthArr = nullptr;
	arr = getInput(index, size);
	insertArr = new double[size];
	selectArr = new double[size];
	fifthArr = new double[size];
	updateArrays(arr, size, insertArr, selectArr, fifthArr);
	// function 1
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	
	double res1 = Insertion::insertionSort(insertArr, size, index);

	auto end = chrono::high_resolution_clock::now();
	double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt");
	myfile << "Time taken by function <Insertion::insertionSort> is : " << fixed<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	
	// function 2
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	
	double res2 = selection::selectionSort(selectArr, 0, size - 1, index);
	
	end = chrono::high_resolution_clock::now();
	time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function <selection::selectionSort> is : " << fixed<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);

	// function 3
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);

	double res3 = fifth::fifthSort(fifthArr, size, index);

	end = chrono::high_resolution_clock::now();
	time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;

	myfile << "Time taken by function <fifth::fifthSort> is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);

	cout << setprecision(4) << fixed;
	cout <<"Insertion sort i'th element: "<<res1<<endl<<"Selection i'th element: "<<res2<<endl<<"Quintuplet algorithm i'th element: "<<res3;
	delete[] arr;
	delete[] insertArr;
	delete[] selectArr;
	delete[] fifthArr;

}

