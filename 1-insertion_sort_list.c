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
		if (temp->n < prev->n)
		{

			print_list(*list);
		}
	}
}

void swap(listint_t **list, listint_t *node, listint_t *prev)
{
	listint_t *temp = NULL;



}
