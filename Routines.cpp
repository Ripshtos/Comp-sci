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
	index++;
	return index;
}


//[ 1.2.3.4.5.6.7.1.1.1.1.1.1]
int Search2(int * v, int m, int x)
{
	int left = 0;
	int right = m;
	int middle = m / 2;
	int index = -1;

	while (right != left) // binary search with a time complexity of O(log m)
	{
		if (v[middle] == x ) 
		{
			return middle + 1;
		}
		if (middle > x -1 )
		{
			right = middle;
			middle = (left + right)/2;
		}
		else if (middle < x - 1 ) 
		{
			left = middle;
			middle = (left + right) / 2;
		}
	}

	return -1;
	
	
}


int Search3(int * v, int m, int x)
{
	return -1;
}
