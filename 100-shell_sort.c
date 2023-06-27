#include "sort.h"

/**
* shell_sort - shell sort algorithm
*
* @array: array to sort
* @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	long int x = 1;
	long int y, z, tmp;

	if (size < 2)
		return;

	while (x < (long int)size / 3)
		x = x * 3 + 1;

	while (x > 0)
	{
		for (y = x; y < (long int) size; y++)
		{
			tmp = array[y];
			for (z = y; z >= x && array[z - x] > tmp; z = z - x)
				array[z] = array[z - x];
			array[z] = tmp;
		}
		print_array(array, size);
		x = (x - 1) / 3;
	}
}
