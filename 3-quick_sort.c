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
	if (array == NULL || size <= 1)
	{
		return;
	}
	/*quick_sort_recursive(array, 0, size - 1, size);*/
	_quick_sort(array, size, array, size);
}


/**
 * _quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * @sub_array: index of the start the subarray
 * @sub_size: index of the end the subarray
 * Return: Nothing.
 */
void _quick_sort(int *array, size_t size, int *sub_array, size_t sub_size)
{
	size_t i = 0, j = 1;
	int pivot, temp;

	pivot = sub_array[sub_size - 1];
	while (i < sub_size)
	{
		if (sub_array[i] < pivot)
		{
			i++;
			j++;
			continue;
		}
		else
		{
			while (sub_array[j] >= pivot && j < (sub_size - 1))
				j++;

			if (j < sub_size && i != j)
			{
				temp = sub_array[j];
				sub_array[j] = sub_array[i];
				sub_array[i] = temp;
				print_array(array, size);
			}
			else
				j--;
		}
		if (j == sub_size - 1)
		{
			if (i > 1)
			{
				_quick_sort(array, size, sub_array, i);
			}
			if (i < sub_size - 2)
			{
				_quick_sort(array, size, sub_array + i + 1, sub_size - i - 1);
			}
			break;
		}
	}
}

