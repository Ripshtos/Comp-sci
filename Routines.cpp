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


int Search2(int* v, int m, int x) { // binary search with a time complexity of O(log m)
	int left = 0, right = m - 1;
	int counter = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == x) {
			cout << "Number of divisions : " << counter << endl;
			return mid;
		}
		else if (v[mid] < x) {
			left = mid + 1;
			counter++;
		}
		else {
			right = mid - 1;
			counter++;
		}
	}
	return -1;
}

int SearchN(int * v, int m, int x)// binary search for the last 0's index with a time complexity of O(log m)
{
	int left = 0, right = m - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == 0 && v[mid-1] != 0 && v[mid+1] == 0) {
			return mid;
		}
		else if (v[mid] > 0) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
    return -1;
}

int Search3(int * v, int n, int x)// binary searches only from 0-N therefore has a time complexity of O(long n)
{
	int right = SearchN(v, n, x);
	int left = 0;
	int counter = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == x) {
			cout << "Number of divisions : " << counter << endl;
			return mid;
		}
		else if (v[mid] < x) {
			left = mid + 1;
			counter++;
		}
		else {
			right = mid - 1;
			counter++;
		}
	}

	return -1;
}
