#include "Array.h"
#include "SortBase.h"

#include <time.h>
#include <iostream>

// generates integer array with random numbers
int* Array::GetNumberArray(int size, int maxrand) {
	srand(time(0));

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
		arr[i] = rand() % maxrand;

	return arr;
}

// prints array linearly
void Array::ShowArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << "\t";

	std::cout << "\n\n";
}

// injects sorting logic
int* Array::Sort(SortBase* sort, int*& arr, int size) {
	sort->SetArray(arr, size);
	return sort->Sort();
}