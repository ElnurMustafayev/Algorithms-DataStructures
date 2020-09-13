#pragma once

// abstract class
class SortBase {
public:
	// sort
	virtual int* Sort() = 0;

	// set class props
	virtual void SetArray(int*& arr, int size) = 0;
};