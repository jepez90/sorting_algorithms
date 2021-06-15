#include "sort.h"
void quick_sort_recursiv(int *array, size_t size, int *sub_array, size_t sub_size);
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
	quick_sort_recursive(array, 0, size - 1, size);
	/*quick_sort_recursiv(array, size, array, size);*/
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
	j = i + 1;

	printf("i:%ld\tj:%ld\tbegin:%ld\tend:%ld\tpivot:%d\n", i, j, begin, end, pivot);
	while (i <= end)
	{

		if (array[i] < pivot)
		{
			i++;
			j++;
			if (j == end)
				i = j;
			printf("i:%ld\tj:%ld\n", i, j);
		}
		else
		{
			while (array[j] >= pivot && j < end)
			{
				j++;
				printf("i:%ld\tj:%ld\n", i, j);
			}
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



/*void quick_sort_recursiv(int *array, size_t size, int *sub_array, size_t sub_size)
{
	size_t i = 0, j = 1;
	int pivot, temp;
	print_array(sub_array, sub_size);
	pivot = sub_array[sub_size - 1];
	printf("pivot: %d ", pivot);
	while (i < sub_size)
	{

		if (sub_array[i] < pivot)
		{
			i++;
			j++;
		}
		else
		{
			while (sub_array[j] >= pivot && j < (sub_size - 1))
			{
				j++;
			}
			printf("j: %ld\t sub_size:%ld\n", j,sub_size);

			temp = sub_array[j];
			sub_array[j] = sub_array[i];
			sub_array[i] = temp;

			print_array(array, size);

		}
		if (j == sub_size - 1)
		{
			if (i > 1)
			{
				quick_sort_recursiv(array, size, sub_array, i);
			}
			if (i < sub_size - 2)
			{
				quick_sort_recursiv(array, size, sub_array + i + 1, sub_size - i - 1);
			}
			break;
		}
	}
}*/

