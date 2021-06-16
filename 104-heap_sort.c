#include "sort.h"

void build_heap(int *array, size_t size);
void sift_down(int *array, size_t top, size_t last, size_t size);

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t last = size - 1;
	int max;

	if (array == NULL)
		return;

	build_heap(array, size);
	while (last > 0)
	{
		/* swap (0, last) */
		max = array[0];
		array[0] = array[last];
		array[last] = max;
		last--;
		print_array(array, size);
		sift_down(array, 0, last, size);
	}
}


/**
 * build_heap - sort the heap tree tree in asc order
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void build_heap(int *array, size_t size)
{
	int i;

	/* i es el indice mayor impar */
	if (size % 2 == 0)
		i = (int)size - 1;
	else
		i = (int)size - 2;

	for (; i > 0; i -= 2)
	{
		sift_down(array, i / 2, size - 1, size);
	}
}


/**
 * sift_down - sort the heap tree in asc order starting in top
 * @array: Array of integers to be used.
 * @top: index in the array when start the sort the tree.
 * @last: index of the las unsorted element
 * @size: Size of the array.
 * Return: Nothing.
 */
void sift_down(int *array, size_t top, size_t last, size_t size)
{
	size_t next, indice_del_max;
	int max;

	next = (top * 2) + 1;

	if (next > last)
		return;

	indice_del_max = next;
	if ((next + 1) <= last && array[next + 1] > array[next])
		indice_del_max = next + 1;

	if (array[top] < array[indice_del_max])
	{
		max = array[indice_del_max];
		array[indice_del_max] = array[top];
		array[top]  = max;

		print_array(array, size);

		/* llamada recursiva */
		sift_down(array, indice_del_max, last, size);
	}

}
