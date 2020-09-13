#include "Array.h"

int main() {

	// [0]
	Array arr(1);

	// []
	Array arr2(0);
	// [1, 2, 3]
	arr2.AddRange(new int[3]{ 1, 2, 3 }, 3);


	// [0, 1, 2, 3]
	arr.AddRange(arr2);
	// [1, 2, 3, 10, 1]
	arr.Add(10).Add(arr[1]).Delete(0);
	// [1, 2, 10, 1]
	arr.Delete(Array::WHICH::middle)
		// [7, 2, 9, 7]
		.Replace(1, 7)
		.Replace(10, 9);


	//	7	2	9	7
	Array::ShowArray(arr);

}