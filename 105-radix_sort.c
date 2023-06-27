#include "sort.h"
/**
* pos10 - calculates a positive power of 10
* @power10: power of 10 to calculate
* Return: answer which is the final result
*/
unsigned int pos10(unsigned int power10)
{
	unsigned int i, answer;

	answer = 1;
	for (i = 0; i < power10; i++)
		answer *= 10;
	return (answer);
}

/**
* count_sort - sorts an array of integers in ascending order
* @array: array to be sorted
* @size: size of the array to be sorted
* @num: number to sort
*
* Return: 1 to keep sorting, otherwise 0
*/
unsigned int count_sort(int *array, size_t size, unsigned int num)
{
	int i, count[10] = {0};
	int *varcopy = NULL;
	size_t j, temp, total = 0;
	unsigned int var1, var2, sort = 0;

	var2 = pos10(num - 1);
	var1 = var2 * 10;
	varcopy = malloc(sizeof(int) * size);
	if (varcopy == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		varcopy[j] = array[j];
		if (array[j] / var1 != 0)
			sort = 1;
	}
	for (i = 0; i < 10 ; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] % var1) / var2] += 1;
	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[(varcopy[j] % var1) / var2]] = varcopy[j];
		count[(varcopy[j] % var1) / var2] += 1;
	}
	free(varcopy);
	return (sort);
}

/**
* radix_sort - Radix sort algorithim
* @array: array to sort
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; sort == 1; i++)
	{
		sort = count_sort(array, size, i);
		print_array(array, size);
	}
}
