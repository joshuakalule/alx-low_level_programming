/**
 * set_bit - sets the value of a bit at a given index to 1
 * @n: number
 * @index: index to set
 *
 * Return: 1 if worked otherwise -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 64)
		return (-1);
	if (!(*n >> index & 1))
	{
		*n |= 1 << index;
		return (1);
	}
	return (-1);
}
