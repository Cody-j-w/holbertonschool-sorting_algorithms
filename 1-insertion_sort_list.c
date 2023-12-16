#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * 
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_list = *list, *temp = NULL, *next = NULL;
	
	if (*list != NULL)
	{
		if ((*list)->next != NULL)
			temp = (*list)->next;
		while (temp != NULL)
		{
			next = temp->next;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp->prev = NULL;
			temp->next = NULL;

			insert(&sorted_list, temp);
			temp = next;
			print_list(sorted_list);
		}
	}
}

void insert(listint_t **list, listint_t *node)
{
	listint_t *temp = NULL;

	if (*list == NULL)
	{
		*list = node;
	}
	else if ((*list)->n >= node->n)
	{
		node->next = *list;
		node->next->prev = node;
		*list = node;
	}
	else
	{
		temp = *list;
		while (temp->next != NULL && temp->next->n < node->n)
			temp = temp->next;
		node->next = temp->next;
		if(temp->next != NULL)
			node->next->prev = node;
		temp->next = node;
		node->prev = temp;
	}
}
