#include "sort.h"

int get_digit_number(int number, int digit);
int power(int number, int power);
void sort_k(int *array, int *aux_array, size_t size, int k);


/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: Array of integers to be used.
 * @size: Size of the array.
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int k, max = 0, *aux_array = NULL;
	size_t i;

	/* validate the input */
	if (array == NULL || size < 2)
		return;

	/* 1 create the auxiliar array*/
	aux_array = malloc(size * sizeof(int));
	if (aux_array == NULL)
		return;

	k = 1;
	/* 2 loop for each k, it means the digits count of the numbers */
	while (1)
	{
		sort_k(array, aux_array, size, k);

		/* 6 copy the auxiliary array in array */
		for (i = 0; i < size; i++)
		{
			array[i] = aux_array[i];
			if (max < array[i])
				max = array[i];
		}

		print_array(array, size);
		/* change k */
		if (max / power(10, k) == 0)
			break;
		k++;
	}

}


/**
 * sort_k - sorts an array for the k digit position given
 * @array: Array of integers to be used.
 * @aux_array: Array on the values will be sorted.
 * @size: Size of the array.
 * @k: digit position on the numbers as reference to be sorted
 * Return: number in given position.
 */
void sort_k(int *array, int *aux_array, size_t size, int k)
{
	int digit_k, count_array[10] = {0};
	size_t i;

	/* 3 traverse the array */
	for (i = 0; i < size; i++)
	{
		/* obtener digito k */
		digit_k = get_digit_number(array[i], k);
		/* sumar 1 en count_array en la posicion k */
		count_array[digit_k]++;
	}

	/* 4 substract 1 to position 0 in count_array */
	count_array[0]--;

	/* traverse count_array */
	for (i = 1; i < 10; i++)
	{
		/* sumar 1 en count_array en la posicion k */
		count_array[i] += count_array[i - 1];
	}

	/* 5 traverse the array  */
	for (i = 1; i <= size; i++)
	{
		/* obtener digito k */
		digit_k = get_digit_number(array[size - i], k);
		/**
		 * copy each value in the auxiliar array in the position indicate
		 * in the count_array in k position
		 * and decrease this value
		 */
		aux_array[count_array[digit_k]--] = array[size - i];
	}
}


/**
 * get_digit_number - calculates the number in the digit position
 * the position starts in 1 from the rigth
 * @number: nomber to be checked.
 * @digit: number of the digit to be returned.
 * Return: number in given position.
 */
int get_digit_number(int number, int digit)
{
	int base = power(10, digit);

	number %= base;
	number /= (base / 10);
	return (number);
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
