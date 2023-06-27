#include "sort.h"

/**
 * sortarray - sort an array of integers using quick_sort function
 * @array: array to sort
 * @minvalue: minimum value
 * @maxvalue: max value
 * @size: the size of the array to sort
 * Return: index + 1
 */
size_t sortarray(int *array, ssize_t minvalue, ssize_t maxvalue, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[maxvalue];
	i = minvalue - 1;
	for (j = minvalue; j < maxvalue; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[maxvalue] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[maxvalue];
		array[maxvalue] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* partsort - sorts an array partition recursively
* @array: array to be sorted
* @minindex: min index of the partition
* @maxindex: max index of the partition
* @size: array size
*/
void partsort(int *array, ssize_t minindex, ssize_t maxindex, size_t size)
{
	ssize_t pivot;

	if (minindex < maxindex)
	{
		pivot = sortarray(array, minindex, maxindex, size);
		partsort(array, minindex, pivot - 1, size);
		partsort(array, pivot + 1, maxindex, size);

	}
}

/**
* quick_sort - sorts an array with quick sort algo
* @array: The array to be sorted
* @size: The size of the array to be sorted
*/
void quick_sort(int* array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	partsort(array, 0, size - 1, size);
}
