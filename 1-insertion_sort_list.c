#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * 
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *prev = NULL, *next = NULL;
	listint_t *dprev = NULL, *dnext = NULL;
	
	while (temp != NULL)
	{
		if (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				prev = temp->prev;
				dprev = prev->prev;
				next = temp->next;
				dnext = next->next;
				printf("prev: %d", prev->n);
				printf("next: %d", next->n);
				if (dprev != NULL)
					printf("dprev: %d", dprev->n);
				if (dnext != NULL)
					printf("dnext: %d", dnext->n);
			}
		}
		temp = temp->next;
	}
	/**
	 * while (temp != NULL)
	 * {
	 * 	next = temp->next;
	 * 	temp->prev = NULL;
	 * 	temp->next = NULL;
	 * 
	 * 	insert(&sorted_list, temp);
	 * 	temp = next;
	 * }
	 * *list = sorted_list;
	 */
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
