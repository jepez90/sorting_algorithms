#include "sort.h"
/**
 * swap_func - sorts a doubly linked list of integers in ascending order using
 * the Cocktail shaker sort algorithm.
 * @list: pointer to head of list to be sorted
 * @current: Pointer to the current node in the list.
 * Return: Nothing
 */
void swap_func(listint_t **list, listint_t *current)
{
	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		*list = current->next;

	current->next->prev = current->prev;
	current->prev = current->next;
	current->next = current->next->next;
	current->prev->next = current;
	if (current->next != NULL)
		current->next->prev = current;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: pointer to head of list to be sorted.
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *last_node;
	int change_exists;

	if (list == NULL || *list == NULL)
		return;
	last_node = *list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	while (1)
	{
		current = *list;
		change_exists = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{  /*swap node*/
				swap_func(list, current);
				change_exists = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		current = last_node;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				current = current->prev;
				swap_func(list, current);
				change_exists = 1;
				print_list(*list);
			}
			current = current->prev;
		}
		if (change_exists == 0)
			break;
	}
}
