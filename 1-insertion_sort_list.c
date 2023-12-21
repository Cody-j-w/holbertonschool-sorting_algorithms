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
			pull(list, temp, prev);
			swap(list, temp, prev);
			print_list(*list);
		}
	}
}

void swap(listint_t **list, listint_t *node, listint_t *current)
{
	listint_t *temp = NULL, *prev = current->prev;

	temp->next = current;
	temp->prev = prev;
	current->prev = temp;
	if (temp->prev != NULL)
		prev->next = temp;
}

void pull(listint_t **list, listint_t *node, listint_t *prev)
{
	prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = prev;
	node->prev = NULL;
	node->next = NULL;
}
