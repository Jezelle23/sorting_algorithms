#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* mergesub - sorts and merges the sub arrays
* @start: starting index
* @middle: end index
* @end: end index
* @dest: destination for the data
* @source: source of the data
*
* Return: void
*/
void mergesub(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t x, y, z;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	x = start;
	y = middle;
	for (z = start; z < end; z++)
	{
		if (x < middle && (y >= end || source[x] <= source[y]))
		{
			dest[z] = source[x];
			x++;
		}
		else
		{
			dest[z] = source[y];
			y++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
* mergesplit - recursively splits the array
* @start: starting index
* @end: ending index
* @array: the array to sort
* @clone: a clone of the array
*/
void mergesplit(size_t start, size_t end, int *array, int *clone)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	mergesplit(start, middle, array, clone);
	mergesplit(middle, end, array, clone);
	mergesub(start, middle, end, array, clone);
	for (middle = start; middle < end; middle++)
		clone[middle] = array[middle];
}

/**
* merge_sort - sorts an array of integers
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t x;
	int *dupli;

	if (array == NULL || size < 2)
		return;
	dupli = malloc(sizeof(int) * size);
	if (dupli == NULL)
		return;
	for (x = 0; x < size; x++)
		dupli[x] = array[x];
	mergesplit(0, size, array, dupli);
	free(dupli);
}
