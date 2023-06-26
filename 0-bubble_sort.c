#include "sort.h"

/**
 * swap - swap the 2  pointers to the  integers
 *
 * @a: first int pointer
 * @b: second int pointer
 */
void swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/**
 * bubble_sort - sort array of integers in ascending order
 * @array: the array to sort and print
 * @size: size of array to sort
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int varA = 0, varB = 0;

	if (size <= 1)
		return;

	for (varA = 0; varA < (size - 1); varA++)
		for (varB = 1; varB < size; varB++)
			if (array[varB - 1] > array[varB])
			{
				swap(&array[varB - 1], &array[varB]);
				print_array(array, size);
			}
}
