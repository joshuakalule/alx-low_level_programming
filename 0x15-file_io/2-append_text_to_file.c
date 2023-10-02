#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: path to the file
 * @text_content: text to be appended
 *
 * Return: 1 (success) , -1 (fail)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fp;
	size_t len;
	ssize_t bytes_written;

	if (!filename || access(filename, W_OK) != 0)
		return (-1);

	fp = open(filename, O_WRONLY | O_APPEND | O_EXCL, S_IRUSR | S_IWUSR);
	if (fp == -1)
		return (-1);

	if (text_content)
	{
		len = strlen(text_content);
		bytes_written = write(fp, text_content, len);
		if ((size_t)bytes_written != len)
		{
			close(fp);
			return (-1);
		}
	}
	close(fp);
	return (1);
}
