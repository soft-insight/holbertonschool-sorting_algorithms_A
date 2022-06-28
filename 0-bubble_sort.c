#include "sort.h"

/**
 * swap - functions that swaps two pointers
 *
 * @number_a: pointer to number_a
 * @number_b: pointer to number_b
 * Return: void
 */

void swap(int *number_a, int *number_b)
{
	int temp = *number_a;

	*number_a = *number_b;
	*number_b = temp;
}

/**
 * bubble_sort - function sorting array
 *
 * @array: pointer to array
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int checker = 0;

	if (array == NULL)
		return;

	for (; i < (size - 1); i++)
	{
		if (array[i] > array[i + 1])
		{
			swap(array + i, array + (i + 1));
			print_array(array, size);
			checker = 1;
		}
	}
	if (checker == 1)
		bubble_sort(array, size);
}
