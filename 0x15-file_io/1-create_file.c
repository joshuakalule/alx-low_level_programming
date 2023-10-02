#include "main.h"

/**
 * create_file - creates a file
 * @filename: path to the file
 * @text_content: text to put in the file
 *
 * Return: 1 (success) otherwise 0 (fail)
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t len;
	ssize_t bytes_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		len = strlen(text_content);
		bytes_written = write(fd, text_content, len);
		if ((size_t)bytes_written != len)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
