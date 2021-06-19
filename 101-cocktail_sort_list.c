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

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: pointer to head of list to be sorted.
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int change_exists;

	if (list == NULL || *list == NULL)
		return;

	while (1)
	{
		current = *list;
		change_exists = 0;

		/* bubble sort to right */
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{  /*swap node*/
				swap_func(list, current);
				change_exists = 1;
			}
			else
				current = current->next;
		}

		/* bubble sort to left */
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{	/* mov the current to prev and then swap*/
				current = current->prev;
				swap_func(list, current);
				change_exists = 1;
			}
			current = current->prev;
		}
		/* if the list is already ordered, exit of the infinity loop */
		if (change_exists == 0)
			break;
	}
}
