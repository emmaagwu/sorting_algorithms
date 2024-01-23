#include "sort.h"

void swap(int *a, int *b);
size_t lomuto_partition(int *array, size_t low, size_t high);
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, int low, int high);




/**
 *swap- swaps the elements of the array
 *@a: the first element to be sorted
 *@b: the second element to be sorted
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/**
 *lomuto_partition- Order a subset of an array of integers according to
 *                    the lomuto partition
 *@array: the array to be sorted
 *@low: the starting index of the current partition
 *@high: the ending index of the current partition
 *
 *Return: The final partition index
 */

size_t lomuto_partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t j, i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
		swap(&array[i + 1], &array[high]);
		print_array(array, high + 1);
	}
	
	return (i + 1);
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;

	lomuto_sort(array, 0, size - 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, int low, int high)
{
	size_t partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high);
		lomuto_sort(array, low, partition_index - 1);
		lomuto_sort(array, partition_index + 1, high);
	}
}
