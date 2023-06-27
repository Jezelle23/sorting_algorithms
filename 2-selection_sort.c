#include "sort.h"
/**
 * selection_sort - sort an array of integers using selection sort function
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int x = 0, y = 0, smallvar = 0;
	int *change = NULL;

	if (!array || size < 2)
		return;
	for (; x < size; x++)
	{
		smallvar = x;
		change =  malloc(sizeof(int) * 1);
		*change = *(array + x);
		for (y = x + 1; y < size; y++)
		{
			if (*(array + y) < *(array + smallvar))
			{
				smallvar = y;
			}
		}
		if (x < smallvar)
		{
		*(array + x) = *(array + smallvar);
		*(array + smallvar) = *change;
		free(change);
		print_array(array, size);
		}
		else
			free(change);
	}
}
