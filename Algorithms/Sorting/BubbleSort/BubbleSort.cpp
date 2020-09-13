#include "BubbleSort.h"

// set privates
void BubbleSort::SetArray(int*& arr, int size) {
	this->_array = arr;
	this->_size = size;
}

// sorting logic
int* BubbleSort::Sort() {
	// untill sorted
	while (!IsSorted())
		// go for each
		for (int i = 0; i < this->_size - 1; i++)
			// i > i+1
			if (IsGreater(i))
				// i <~ ~> i+1
				Swap(i);

	// return sorted array
	return this->_array;
}

// check is the next greater
bool BubbleSort::IsGreater(int index) {
	return this->_array[index] > this->_array[index + 1];
}

// swap two elements
void BubbleSort::Swap(int index) {
	int temp = this->_array[index];
	this->_array[index] = this->_array[index + 1];
	this->_array[index + 1] = temp;

}

// check is array sorted
bool BubbleSort::IsSorted() {
	bool issorted = true;   // flag

	for (int i = 0; i < this->_size - 1; i++)
		if (IsGreater(i))
			// array is not sorted
			issorted = false;

	return issorted;
}