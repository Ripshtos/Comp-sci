#include "Header.h"

int Search1(int * v, int m, int x)
{
	int index = -1;
	for (int i = 0; i < m; i++)
	{
		if (v[i] == x) 
		{
			index = i;
		}
	}
	
	return index;
}


//[ 1.2.3.4.5.6.7.1.1.1.1.1.1]
/*
int Search2(int * v, int m, int x)
{
	int left = 0;
	int right = m;
	int middle = m / 2;
	

	while (right != left) // binary search with a time complexity of O(log m)
	{
		 middle = (left + right) /  2;
		if (v[middle] == x ) 
		{
			return middle + 1;
		}

		if (middle > x -1 )
		{
			right = middle;
			
		}

		else if (middle < x - 1 ) 
		{
			left = middle;
			middle = (left + right) / 2;
		}
	}


	return -1;
	
	
}
*/


int Search2(int * v, int m, int x) { // binary search with a time complexity of O(log m)
	int left = 0, right = m - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == x) {
			return mid;
		}
		else if (v[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}


	return -1;
}





/*
int binarySearchNonZero(int v[], int left, int right, int x) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == 0) {
			int lresult = binarySearchNonZero(v, left, mid - 1, x);
			if (lresult == -1) {
				return binarySearchNonZero(v, mid + 1, right, x);
			}
			return lresult;
		}
		else if (v[mid] == x) {
			return mid;
		}
		else if (v[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}
*/

int Search3(int * v, int m, int x)
{
	return -1;
}
