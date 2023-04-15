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

int Search2(int * v, int m, int x)
{
	return -1;
}


int Search3(int * v, int m, int x)
{
	return -1;
}
