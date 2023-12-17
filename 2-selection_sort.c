#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts an array by iterating through and picking
 * the lowest value, swapping it with the current value
 * @array: the array beingt sorted
 * @size: the size of the array being sorted
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, mindex;
	int min;

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
			print_array(array, size);
		}
	}
}
