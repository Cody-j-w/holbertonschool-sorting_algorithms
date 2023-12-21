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
			pull(temp, prev);
			swap(temp, prev);
			print_list(*list);
		}
		temp = next;
	}
}

void swap(listint_t *node, listint_t *current)
{
	listint_t *prev = current->prev;

	node->next = current;
	node->prev = prev;
	current->prev = node;
	if (node->prev != NULL)
		prev->next = node;
}

void pull(listint_t *node, listint_t *prev)
{
	prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = prev;
	node->prev = NULL;
	node->next = NULL;
}
