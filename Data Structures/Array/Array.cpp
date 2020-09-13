#include "Array.h"

// Constructor
Array::Array(unsigned int size) {
	this->_size = size;

	// fill array with zero values
	this->_arrptr = new int[size] {0};
}

// [] operator overloading (indexer)
int Array::operator[](int index) {
	return this->_size > index
		? this->_arrptr[index]
		: -1;
}



// Check array is null
bool Array::IsNull() {
	return this->_arrptr == nullptr;
}

// Get index of item (index/-1)
int Array::IndexOf(int item) {
	for (size_t i = 0; i < this->_size; i++)
		if (this->_arrptr[i] == item)
			// if found
			return i;

	// if not found
	return -1;
}

// @what <~ replace ~> @to
Array& Array::Replace(int what, int to) {
	for (size_t i = 0; i < this->_size; i++)
		// if item found
		if (this->_arrptr[i] == what)
			// replace it
			this->_arrptr[i] = to;

	// return this object
	return *this;
}

// Add one item in array
Array& Array::Add(int item) {
	// create array with (size + 1)
	int* result = new int[this->_size + 1];
	
	// copy main array
	for (size_t i = 0; i < this->_size; i++)
		result[i] = this->_arrptr[i];

	// add new item
	result[this->_size] = item;

	// set privates
	this->_arrptr = result;
	this->_size++;

	// return this object
	return *this;
}

// this->arr[] += arr[]
Array& Array::AddRange(int arr[], int size) {
	// new arrays size
	int newsize = this->_size + size;
	// create new array for concat
	int* result = new int[newsize];

	for (size_t i = 0; i < newsize; i++)
		if (i < this->_size)
			result[i] = this->_arrptr[i];
		else
			result[i] = arr[i - this->_size];

	// set privates
	this->_arrptr = result;
	this->_size = newsize;

	// return this object
	return *this;
}

// this->arr[] += obj.arr[]
Array& Array::AddRange(Array obj) {
	// new arrays size
	int newsize = this->_size + obj._size;
	// create new array for concat
	int* result = new int[newsize];

	// concat main and given arrays
	for (size_t i = 0; i < newsize; i++)
		if (i < this->_size)
			result[i] = this->_arrptr[i];
		else
			result[i] = obj._arrptr[i - this->_size];

	// set privates
	this->_arrptr = result;
	this->_size = newsize;

	// return this object
	return *this;
}

// Delete element by index
Array& Array::Delete(int index) {
	// if array is not empty
	if (this->_size > 0) {
		// create array with (size - 1)
		int* result = new int[this->_size - 1];

		// delete item by index
		for (size_t i = 0; i < this->_size; i++)
			if (i <= index)
				result[i] = this->_arrptr[i];
			else
				result[i - 1] = this->_arrptr[i];

		// set privates
		this->_arrptr = result;
		this->_size--;
	}

	// return this object
	return *this;
}

// Delete element by location (f|m|l)
Array& Array::Delete(WHICH item) {
	switch (item) {
		case WHICH::first:
			return Delete(0);
		case WHICH::middle:
			return Delete(this->_size / 2);
		case WHICH::last:
			return Delete(this->_size - 1);
	}
	return *this;
}



// Check array is null
bool Array::IsNull(Array obj) {
	return obj.IsNull();
}

// Linearly show array
void Array::ShowArray(Array obj) {
	for (int i = 0; i < obj._size; i++)
		std::cout << obj._arrptr[i] << "\t";
	std::cout << std::endl;
}

// Get Length
int Array::Length(Array obj) {
	return obj._size;
}