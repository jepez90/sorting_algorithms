#include "sort.h"
int power(int number, int power);
size_t new_gap(size_t k);

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{

	int hold;
	size_t k, i, j,  gap, l;

	if (array == NULL || size <= 1)
		return;

	for (k = 1; k < size; k++)
	{
		gap = new_gap(k);
		if (gap > (size / 3))
		{
			k--;
			break;
		}
	}

	while (k > 0)
	{
		gap = new_gap(k);
		for (l = 0; l < gap; l++)
		{
			for (i = gap + l; i < size; i += gap)
			{
				for (j = i; j > gap; j -= gap)
				{
					if (array[j - gap] > array[j])
					{
						hold = array[j - gap];
						array[j - gap] = array[j];
						array[j] = hold;
					}
					else
					{
						break;
					}

				}
			}
		}
		print_array(array, size);
		k--;
	}
}

/**
 * new_gap - find the k gap for Knuth secuence
 * @k: index in knuth sequence.
 * Return: the gap.
 */
size_t new_gap(size_t k)
{
	int gap;

	gap = power(3, k) - 1;
	gap /= 2;
	return (gap);
}

/**
 * power - calculates the power for the number
 * @number: base.
 * @power: power.
 * Return: number to power.
 */
int power(int number, int power)
{
	int result;

	if (power == 0)
		return (1);

	result = number;
	while (power-- > 1)
		result *= number;

	return (result);
}
