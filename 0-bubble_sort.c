#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - 
 * @array:
 * @size:
 * 
*/

void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (array[j] > array[j + 1] && j + 1 < size)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
        }
    }
}