#pragma once

#include <iostream>

class Array {

private:
	int* _arrptr;
	unsigned int _size;

public:
	enum class WHICH { first, middle, last };
	Array(unsigned int size);
	int operator[](int index);

	bool IsNull();
	int IndexOf(int item);
	Array& Replace(int what, int to);
	Array& Add(int item);
	Array& AddRange(int arr[], int size);
	Array& AddRange(Array obj);
	Array& Delete(int index);
	Array& Delete(WHICH item);

	static void ShowArray(Array obj);
	static bool IsNull(Array obj);
	static int Length(Array obj);

};