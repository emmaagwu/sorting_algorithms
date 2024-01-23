#include "sort.h"

/**
 *bubble_sort - sorts an array using the Bubble sort algorithm
 *
 *@array: the array to be sorted
 *@size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int tmp = 0;
	int swaped = 0;

	if (array == NULL || size < 2)
		return;

	while (swaped == 0)
	{
		swaped = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swaped = 0;
			}
		}
		len--;
	}
}
