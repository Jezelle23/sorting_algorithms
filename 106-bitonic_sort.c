#include "sort.h"
/**
* compbit - sort bitonic algorithm
* @up: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
*/
void compbit(char up, int *array, size_t size)
{
	size_t x, var;
	int swap;

	var = size / 2;
	for (x = 0; x < var; x++)
	{
		if ((array[x] > array[x + var]) == up)
		{
			swap = array[x];
			array[x] = array[x + var];
			array[x + var] = swap;
		}
	}
}

/**
* bitmerge - merge sub arrays
* @up: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
*
* Return: void
*/
void bitmerge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	compbit(up, array, size);
	bitmerge(up, array, size / 2);
	bitmerge(up, array + (size / 2), size / 2);
}

/**
* bit_sort - bitonic sort algorithm
* @up: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
* @t: total size of the original array
*
* Return: void
*/
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitmerge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}
/**
* bitonic_sort - sorts an array in ascending order
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void bitonic_sort(int* array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
