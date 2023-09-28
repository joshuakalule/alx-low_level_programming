/**
 * get_bit - gets the value of a bot at a given index
 * @n: number
 * @index: index to check
 *
 * Return: value of the bit at index or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	bit = ((n >> index) & 1);
	if (index > 64)
		return (-1);
	return (bit);
}
