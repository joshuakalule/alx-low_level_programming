/**
 * get_endianness - checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int num = 1567891234;
	char *p = (char *) &num;

	if (*p == 0x22)
		return (1);
	else
		return (0);
}
