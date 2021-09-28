#include <iostream>
#include "solution.h"

using namespace std;

int main(void)

{
	int arr[5] = {1, 2, 4, 3, 5};

	int arr2[5] = {1, 2, 4, 3, 5};

	int len = 5;

	insertion_sort(arr, len);

	bubble_sort(arr2, len);

	return 0;
}
