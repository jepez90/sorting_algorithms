#include "sort.h"
/*
*
*
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *compared_node;

	if (*list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		printf("%d\t", current->n);
		compared_node = current;
		current = current->next;
		while (compared_node->prev != NULL)
		{
			if (compared_node->prev->n > compared_node->n)
			/* swap nodes*/
			{
				compared_node->prev->next = compared_node->next;
				if (compared_node->next != NULL)
					compared_node->next->prev = compared_node->prev;
				compared_node->next = compared_node->prev;
				compared_node->prev = compared_node->next->prev;
				if (compared_node->prev != NULL)
					compared_node->prev->next = compared_node;
				else
					*list = compared_node;
				compared_node->next->prev = compared_node;
				print_list(*list);
			}
		}
	}
}
