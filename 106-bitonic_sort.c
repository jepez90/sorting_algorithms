#include "sort.h"

void _bitonic_sort(int *array, size_t size, int order, size_t total);
void merge(int *array, size_t size, int order);


/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_bitonic_sort(array, size, 1, size);
}



/**
 * _bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm (recursive function)
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * @order: 1 if the order sort of the section is asc, 0 if is desc
 * @total: Size of the full array, for print.
 * Return: Nothing.
 */
void _bitonic_sort(int *array, size_t size, int order, size_t total)
{
	size_t half = size >> 1;

	printf("Merging [%ld/%ld] (%s):\n", size, total, order ? "UP" : "DOWN");
	print_array(array,  size);


	/* call recursion */
	if (half > 1)
		_bitonic_sort(array, half, 1, total);
	if ((size - half) > 1)
		_bitonic_sort(array + half, size - half, 0, total);

	/* merge */
	merge(array, size, order);

	printf("Result [%ld/%ld] (%s):\n", size, total, order ? "UP" : "DOWN");
	print_array(array,  size);

}

/**
 * merge - merge 2 subarrays useng bitonic secuences
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * @order: 1 if the order sort of the section is asc, 0 if is desc
 * Return: Nothing.
 */
void merge(int *array, size_t size, int order)
{
	int hold, half, i;

	if (size > 1)
	{
		half = size >> 1;
		for (i = 0; i < half; i++)
			if ((array[i + half] < array[i]) == order)
			{
				hold = array[i + half];
				array[i + half] = array[i];
				array[i] = hold;
			}
		merge(array, half, order);
		merge(array + half, half, order);
	}
}
