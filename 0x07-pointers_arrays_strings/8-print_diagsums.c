#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of a
 *                  square matrix of integers
 * @a: matrix of integers
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int major = 0, minor = 0;
	int i = 0, j = size - 1;

	while (i < size && j >= 0)
	{
		major += *(a + i * size + i);
		minor += *(a + j * size + i);
		i++;
		j--;
	}
	printf("%d, %d\n", major, minor);
}
