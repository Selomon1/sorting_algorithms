#include "sort.h"

/* prototypes for the below functions */
void swap_(int *curr, int *nex);
int lu_partition(int *array, size_t size, int l_end, int r_end);
void lomuto_part_sort(int *array, size_t size, int l_end, int r_end);
void quick_sort(int *array, size_t size);

/**
 * swap_ - swaps two integers of an array
 * @curr: first integer to swap
 * @nex: second integer to swap
 * Return: void
 */

void swap_(int *curr, int *nex)
{
	int temp;

	temp = *curr;
	*curr = *nex;
	*nex = temp;
}
/**
 * lu_partition - implementation of lomuto partition
 * @array: array of integers
 * @size: size of an array
 * @l_end: left end of starting index of an array
 * @r_end: right end of ending index of an array
 * Return: 0
 */

int lu_partition(int *array, size_t size, int l_end, int r_end)
{
	int *pivot, i, j;

	pivot = array + r_end;
	for (i = j = l_end; j < r_end; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap_(array + i, array + j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap_(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}
/**
 * lomuto_part_sort - implementation of the quick sort with recursion
 * @array: array of integers
 * @size: szie of an array
 * @l_end: left end starting index of an array
 * @r_end: right end ending index of an array
 * Return: 0
 */

void lomuto_part_sort(int *array, size_t size, int l_end, int r_end)
{
	int s1;

	if (r_end - l_end > 0)
	{
		s1 = lu_partition(array, size, l_end, r_end);
		lomuto_part_sort(array, size, l_end, s1 - 1);
		lomuto_part_sort(array, size, s1 + 1, r_end);
	}
}

/**
 * quick_sort - sorts an array of integers using quick sort
 * @array: list of array
 * @size: size of an array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_part_sort(array, size, 0, size - 1);
}
