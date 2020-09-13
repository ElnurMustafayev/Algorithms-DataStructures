#include "BubbleSort.h"
#include "Array.h"

int main() {

	// create array
	int arrsize = 100;
	int* arr = Array::GetNumberArray(arrsize);

	// print not sorted array
	Array::ShowArray(arr, arrsize);

	// sort array
	BubbleSort bs;
	Array::Sort(&bs, arr, arrsize);

	// print sorted array
	Array::ShowArray(arr, arrsize);

}