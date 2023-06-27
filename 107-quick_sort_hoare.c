#include "sort.h"
/**
* sortarray - sort array using Hoare version
* @array: array to sort
* @min: lowest index
* @max: highest index
* @size: size of the array
*
* Return: sort index
*/
size_t sortarray(int *array, ssize_t min, ssize_t max, size_t size)
{
	int switcharr, index;

	index = array[max];
	while (min <= max)
	{
		while (array[min] < index)
			min++;
		while (array[max] > index)
			max--;
		if (min <= max)
		{
			if (min != max)
			{
				switcharr = array[min];
				array[min] = array[max];
				array[max] = switcharr;
				print_array(array, size);
			}
			min++;
			max--;
		}
	}
	return (max);
}

/**
* sortpart - sorts a partition of an array of integers
* @array: array to sort
* @min: lowest index of the partition to sort
* @max: highest index of the partition to sort
* @size: size of the array
*
* Return: void
*/
void sortpart(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t index;

	if (min < max)
	{
		index = sortarray(array, min, max, size);
		sortpart(array, min, index, size);
		sortpart(array, index + 1, max, size);

	}
}

/**
* quick_sort_hoare - sorts an array of integers with quick sort function
* @array: The array to sort
* @size: The size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sortpart(array, 0, size - 1, size);
}
