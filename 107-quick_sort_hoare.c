#include "sort.h"

void array_swap(int *array, size_t first, size_t second);
void _quick_sort_ho(int *array, size_t size, int *sub_array, size_t sub_size);


/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}
	/*quick_sort_recursive(array, 0, size - 1, size);*/
	_quick_sort_ho(array, size, array, size);
}

/**
 * _quick_sort_ho - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * @sub_array: index of the start the subarray
 * @sub_size: index of the end the subarray
 * Return: Nothing.
 */
void _quick_sort_ho(int *array, size_t size, int *sub_array, size_t sub_size)
{
	int pivot = sub_array[sub_size - 1];
	size_t i = 0, j;


	while (sub_array[i] < pivot)
	{
		i++;
		if (i == (sub_size - 1))
			_quick_sort_ho(array, size, sub_array, sub_size - 1);
	}
	j = i + 1;
	while (j < sub_size)
	{
		if (sub_array[j] < pivot)
		{
			if (sub_array[i] != sub_array[j])
			{
				array_swap(sub_array, i, j);
				print_array(array, size);
			}
			j++;
			i++;
		}
		else
		{
			if (j == (sub_size - 1) && sub_array[i] != sub_array[j])
			{
				array_swap(sub_array, i, j);
				print_array(array, size);
			}
			j++;
		}
		if (j == sub_size)
		{
			if (i > 1)
				_quick_sort_ho(array, size, sub_array, i);
			if (i < sub_size - 2)
				_quick_sort_ho(array, size, sub_array + i + 1, sub_size - i - 1);
			break;
		}
	}
}


/**
 * array_swap - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: Array of integers to be used.
 * @first: Size of the array.
 * @second: Size of the array.
 * Return: Nothing.
 */
void array_swap(int *array, size_t first, size_t second)
{
	int hold;

	hold = array[second];
	array[second] = array[first];
	array[first] = hold;
}


