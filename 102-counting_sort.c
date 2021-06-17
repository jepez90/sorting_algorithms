#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: Array to be sorted.
 * @size: of the array.
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
	int i, index, idx_position, value, max_number = 0;
	int *array_count, *array_copy;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > max_number)
			max_number = array[i];
	array_count = malloc(sizeof(*array_count) * (max_number + 1));
	if (!array_count)
	{
		free(array_count);
		return;
	}
	for (i = 0; i <= max_number; i++)
		array_count[i] = 0;
	for (i = 0; i < (int)size; i++)
	{
		index = array[i];
		array_count[index] += 1;
	}
	for (i = 0; i < max_number; i++)
		array_count[i + 1] += array_count[i];
	print_array(array_count, max_number + 1);
	array_copy = malloc(sizeof(*array_copy) * size);
	if (!array_copy)
	{
		free(array_copy);
		return;
	}
	for (i = 0; i < (int)size; i++)
		array_copy[i] = array[i];
	for (i = size - 1; i >= 0; i--)
	{
		value = array_copy[i];
		idx_position = --(array_count[value]);
		array[idx_position] = value;
	}
	free(array_count);
	free(array_copy);
}
