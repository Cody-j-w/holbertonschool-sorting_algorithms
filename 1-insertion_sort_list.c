#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * 
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *next = NULL, *prev = NULL;
	
	while (temp != NULL)
	{
		next = temp->next;
		prev = temp->prev;
		while (temp->n < prev->n)
		{
			swap(list, temp);
			print_list(*list);
			temp = temp->prev;
		}
	}
}

void swap(listint_t **list, listint_t *node)
{
	int temp = node->n;

	node->n = node->prev->n;
	node->prev->n = temp;
}
