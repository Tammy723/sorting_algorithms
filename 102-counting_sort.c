#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maximum, n;

	for (maximum = array[0], n = 1; n < size; n++)
	{
		if (array[n] > maximum)
			maximum = array[n];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maximum, n;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_max(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (n = 0; n < (maximum + 1); n++)
		count[n] = 0;
	for (n = 0; n < (int)size; n++)
		count[array[i]] += 1;
	for (n = 0; n < (maximum + 1); n++)
		count[n] += count[n - 1];
	print_array(count, maximum + 1);

	for (n = 0; n < (int)size; n++)
	{
		sorted[count[array[n]] - 1] = array[n];
		count[array[n]] -= 1;
	}

	for (n = 0; n < (int)size; n++)
		array[n] = sorted[n];

	free(sorted);
	free(count);
}
