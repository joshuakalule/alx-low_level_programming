/**
 * flip_bits - counts the number of different bits in 2 numbers
 * @n: number 1
 * @m: number 2
 *
 * Return: number of bits the need changing
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;

	while (n | m)
	{
		if ((n & 1) ^ (m & 1))
			count++;
		n >>= 1;
		m >>= 1;
	}
	return (count);
}
