#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked lists of an int in ascending
 * @list: head
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL;

	if (list == NULL)
		return;
	temp = (*list)->next;
	while (temp != NULL)
	{
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		temp = temp->next;
	}
}
