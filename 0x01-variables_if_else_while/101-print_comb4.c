#include <stdio.h>

/**
 * main - entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int n1;
	int n2;
	int n3;

	for (n1 = 48; n1 <= 57; n1++)
	{
		for (n2 = 49; n2 <= 57; n2++)
		{
			for (n3 = 50; n3 <= 57; n3++)
			{
				if ((n2 > n1) && (n3 > n2) == 1)
				{
					putchar(n1);
					putchar(n2);
					putchar(n3);
					if ((n1 == 55 && n2 == 56 && n3 == 57) != 1)
					{
						putchar(44);
						putchar(32);
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}


