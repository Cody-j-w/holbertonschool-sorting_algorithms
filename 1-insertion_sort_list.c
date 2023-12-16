#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * 
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_list = NULL, *temp = *list, *next = NULL;
	
	while (temp != NULL)
	{
		next = temp->next;
		temp->prev = NULL;
		temp->next = NULL;

		insert(&sorted_list, temp);
		temp = next;
		print_lists(sorted_list, next);
	}
	*list = sorted_list;
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

void print_lists(listint_t *sorted, listint_t *unsorted)
{
    int i;

    i = 0;
    while (sorted)
    {
        if (i > 0)
            printf(", ");
        printf("%d", sorted->n);
        ++i;
        sorted = sorted->next;
    }
	i = 0;
	while (unsorted)
	{
		if (i > 0)
			printf(", ");
		printf("%d", unsorted->n);
		i++;
		unsorted = unsorted->next;
	}
	printf("\n");
}
