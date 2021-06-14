#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, posicion_menor;
	int menor;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		menor = array[i];
		posicion_menor = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < menor)
			{
				menor = array[j];
				posicion_menor = j;
			}
		}
		if (posicion_menor != i)
		{
			array[posicion_menor] = array[i];
			array[i] = menor;
			print_array(array, size);
		}

	}
}
