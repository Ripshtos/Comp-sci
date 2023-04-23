#include "Header.h"

/*
Name : Ohad Ripshtos
Id : 323012039
I did the assignment on my own with the approval of Proffesor Yossi
*/


int counter1 = 0;
int counter2 = 0;


	int Search1(int * v, int m, int x)
	{
		int index = -1;
		for (int i = 0; i < m; i++)// simple for loop with a time complexity of O(N)
		{
			if (v[i] == x) 
			{
				index = i;
				break;
			}
		}

		if (index != -1) 
		{
			return index+1;
		}
	
		return index;
	
	}


	void bubbleSort(int * array, int size) {

		// loop to access each array element
		for (int step = 0; step < size - 1; ++step) {

			// check if swapping occurs  
			int swapped = 0;
			// loop to compare array elements
			for (int i = 0; i < size - step - 1; ++i) {
				// compare two array elements
				// change > to < to sort in descending order
				if (array[i] > array[i + 1]) {
					// swapping occurs if elements
					// are not in the intended order
					int temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					swapped = 1;
				}
			}
			// no swapping means the array is already sorted
			// so no need for further comparison
			if (swapped == 0) {
				break;
			}
		}
	}






	int Search2(int* v, int m, int x) { // binary search with a time complexity of O(log m)

		int left = 0, right = m - 1;
		int mid = (left + right) / 2;

		while (left <= right) {
 			mid = (left + right) / 2;
			if (v[mid] == x) {
				cout << "Number of divisions : " << counter1 << endl;
				return mid + 1; // returns the array's cell number
			}
			else if (v[mid] < x && v[mid] != 0) {
				left = mid + 1;
				counter1++;
			}
			else {
				right = mid - 1;
				counter1++;
			}
		}
		return -1;
	}

	int Search3(int * v, int n, int x)// binary searches only from 0-N therefore has a time complexity of O(long n)
	{
		int right = 1;
		while (v[right] != 0) //Search for the first zero with a time complexity of 0(log n), powers of 2.
		{
			right *= 2;
		}

		int left = 0;

		while (left <= right) { // binary search from 1 to approximately N
			int mid = left + (right - left) / 2;
			if (v[mid] == x) {
				cout << "Number of divisions : " << counter2 << endl;
				return mid + 1; // returns the array cell number
			}
			else if (v[mid] <= x && v[mid] != 0) {
				left = mid + 1;
				counter2++;
			}
			else {
				right = mid - 1;
				counter2++;
			}
		}

		return -1;
	}
