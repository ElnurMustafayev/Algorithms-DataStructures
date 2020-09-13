#pragma once

#include "SortBase.h"

class Array {
public:
	// generates integer array with random numbers
	static int* GetNumberArray(int size = 10, int maxrand = 100);

	// prints array linearly
	static void ShowArray(int arr[], int size);

	// injects sorting logic
	static int* Sort(SortBase* sort, int*& arr, int size);
};