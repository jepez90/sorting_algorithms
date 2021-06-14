#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}


/**
 * quick_sort_recursive - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: Array of integers to be used.
 * @begin: index of the start the subarray
 * @end: index of the end the subarray
 * @size: Size of the array.
 * Return: Nothing.
 */
void quick_sort_recursive(int *array, size_t begin, size_t end, size_t size)
{
	size_t i = begin, j;
	int pivot, temp;

	pivot = array[end];

	while (i < end)
	{
		if (array[i] < pivot)
		{
			i++;
			j = i;
		}
		else
		{
			j = i + 1;
			while (array[j] >= pivot && j < end)
				j++;
			/* swap*/
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;

			print_array(array, size);

		}

		if (j == end)
		{	/* si j apunta a pivot */
			if (i > (begin + 1))
			{
				quick_sort_recursive(array, begin, i - 1, size);
			}
			if (1 < (end - i))
			{
				quick_sort_recursive(array,  i + 1, end, size);
			}
			break;
		}
	}
}
