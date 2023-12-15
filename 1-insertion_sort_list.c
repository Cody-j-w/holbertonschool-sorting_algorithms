#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * 
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *sorter = NULL;
	listint_t *temp = NULL;
	if (*list != NULL)
	{
		sorter = *list;
	}
	while (sorter != NULL)
	{
		if (sorter->n < sorter->prev->n)
		{
			temp = sorter->prev;
			sorter->next->prev = sorter->prev;
			temp->next = sorter->next;
			sorter->next = sorter->prev;
			sorter->prev = temp->prev;
			temp->prev = sorter;
			print_list(list);
		}
		else
		{
			sorter = sorter->next;
		}
	}
}
