#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 * sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, change_exists;

	for (j = 0; j < size; j++)
	{
		change_exists = 0;

		for (i = 1; i < (size - j); i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				change_exists = 1;
				print_array(array, size);
			}
		}
		if (change_exists == 0)
			break;
	}
}
