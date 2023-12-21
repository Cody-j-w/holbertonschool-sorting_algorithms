#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - use insertion sort to sort a linked list
 * @list: the list being sorted
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *next = NULL, *prev = NULL;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (temp != NULL)
	{
		next = temp->next;
		prev = temp->prev;
		while (prev != NULL && temp->n < prev->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = temp;
			prev->next = temp->next;
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;
			if (prev->next != NULL)
				prev->next->prev = prev;
			if (temp->prev == NULL)
				*list = temp;

			prev = temp->prev;

			print_list(*list);
		}
		temp = next;
	}
}
