#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sort.h"

/**
 * 
*/


int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[high];
	array[high] = array[i + 1];
	array[i + 1] = temp;
	print_array(array, size);
	return (i + 1);
}

void sort(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = partition(array, low, high, size);

		sort(array, low, index - 1, size);
		sort(array, index + 1, high, size);
	}
}

void quick_sort(int *arr, size_t size)
{

	int high = size - 1, low = 0;

	sort(arr, low, high, size);
}
