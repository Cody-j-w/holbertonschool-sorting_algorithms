#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * 
*/

void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int n = low - 1, i, temp;

	for (i = low; i <= high - 1; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			n++;
			array[i] = array[n];
			array[n] = temp;
		}
	}
	temp = array[n + 1];
	array[n + 1] = array[high];
	array[high] = temp;
	return (n + 1);
}

void sort(int *arr, int low, int high, size_t size)
{
	int set_partition;

	if (low < high)
	{
		set_partition = partition(arr, low, high, size);
		print_array(arr, size);
		sort(arr, low, set_partition - 1, size);
		sort(arr, set_partition + 1, high, size);
	}
}
