#pragma once
#include "SortBase.h"

class BubbleSort : public SortBase {
private: 
	int* _array;
	int _size;

public:
	// set privates
	void SetArray(int*& arr, int size) override;

	// sorting logic
	int* Sort() override;

	// check is the next greater
	bool IsGreater(int index);

	// swap two elements
	void Swap(int index);

	// check is array sorted
	bool IsSorted();
};