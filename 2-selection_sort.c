#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * 
*/

void selection_sort(int *array, size_t size)
{
	int i, j, min, mindex;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		mindex = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[mindex])
			{
				min = array[j];
				mindex = j;
			}
		}
		if (mindex != i)
		{
			array[mindex] = array[i];
			array[i] = min;
			print_array(array);
		}
	}
}
