/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: converted number | 0 Otherwise
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0, i;

	if (!b || !*b)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] < 48 || b[i] > 49)
			return (0);
		result <<= 1;
		if (b[i] == '1')
			result += 1;
	}
	return (result);
}
