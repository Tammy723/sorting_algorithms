#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int mtp;

	mtp = *a;
	*a = *b;
	*b = mtp;
}

/**
 * bubble_sort - Sort an array of integers in an ascending order.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, len = size;
	bool bubb = false;

	if (array == NULL || size < 2)
		return;

	while (bubb == false)
	{
		bubb = true;
		for (n = 0; n < len - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap_ints(array + n, array + n + 1);
				print_array(array, size);
				bubb = false;
			}
		}
		len--;
	}
}
