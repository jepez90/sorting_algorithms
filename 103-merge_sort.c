#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using the Merge
 * sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i, j, k = 0, half = size / 2;
	int half_copy[500] = {0};

	/* call recursion */
	if (half > 1)
		merge_sort(array, half);
	if ((size - half) > 1)
		merge_sort(array + half, size - half);

	/* copy left subarray */
	for (i = 0; i < half; i++)
	{
		half_copy[i] = array[i];
	}
	/* print sub_arrays */
	printf("Merging...\n[left]: ");
	print_array(half_copy, half);
	printf("[right]: ");
	print_array(array + half,  size - half);

	/* merge */
	i = 0;
	j = half;
	while (k < size)
	{
		if (i >= half)
			array[k++] = array[j++];
		else if (j >= size)
			array[k++] = half_copy[i++];
		else
		{
			if (half_copy[i] < array[j])
				array[k++] = half_copy[i++];
			else
				array[k++] = array[j++];
		}
	}
	/* print result */
	printf("[Done]: ");
	print_array(array,  size);
}
