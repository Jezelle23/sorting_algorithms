#include "sort.h"

/**
* counting_sort - counting sort algorithm
* @array: array to be sorted
* @size: size of the array to be sorted
*/
void counting_sort(int *array, size_t size)
{
	int x, max;
	int *countarray = NULL, *varcount = NULL;
	size_t y, temp, total = 0;

	if (array == NULL || size < 2)
		return;
	varcount = malloc(sizeof(int) * size);
	if (varcount == NULL)
		return;
	for (y = 0, max = 0; y < size; y++)
	{
		varcount[y] = array[y];
		if (array[y] > max)
			max = array[y];
	}
	countarray = malloc(sizeof(int) * (max + 1));
	if (countarray == NULL)
	{
		free(varcount);
		return;
	}
	for (x = 0; x <= max; x++)
		countarray[x] = 0;
	for (y = 0; y < size; y++)
		countarray[array[y]] += 1;
	for (x = 0; x <= max; x++)
	{
		temp = countarray[x];
		countarray[x] = total;
		total += temp;
	}
	for (y = 0; y < size; y++)
	{
		array[countarray[varcount[y]]] = varcount[y];
		countarray[varcount[y]] += 1;
	}
	print_array(countarray, max + 1);
	free(countarray);
	free(varcount);
}
