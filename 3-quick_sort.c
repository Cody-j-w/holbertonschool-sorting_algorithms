#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * 
*/

void quick_sort(int *array, size_t size)
{
	int stack = malloc(sizeof(int) * (int)size);
	int top = -1, high, low, index;

	stack[++top] = 0;
	stack[++top] = (int)size - 1;
	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];
		index = partition(array, low, high, size);

		if (index - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = index - 1;
		}
		if (index - 1 < high)
		{
			stack[++top] = index + 1;
			stack[++top] = high;
		}
	}
	free(stack);
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
			print_array(array, size);
		}
	}
	temp = array[n + 1];
	array[n + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (n + 1);
}
