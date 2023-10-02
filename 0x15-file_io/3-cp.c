#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUF_SIZE 1024
/**
 * close_fd - extends close()
 * @fd: file descriptor
 */
void close_fd(int fd)
{
	if (!fd)
		return;
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
		exit(100);
	}
}

/**
 * exit_prog - executes exit sequence upon error
 * @format: format string
 * @file: filename
 * @err: error code
 * @fd_1: fd 1
 * @fd_2: fd 2
 */
void exit_prog(char *format, char *file, int err, int fd_1, int fd_2)
{
	dprintf(STDERR_FILENO, format, file);
	close_fd(fd_1);
	close_fd(fd_2);
	exit(err);
}

/**
 * call_read - executes read sequence
 * @fd_from: fd for input file
 * @fd_to: fd for output file
 * @from_path: input filename
 * @buf: pointer to the buffer
 *
 * Return: bytes read
 */
ssize_t call_read(int fd_from, int fd_to, char *from_path, char *buf)
{
	ssize_t bytes_read;

	bytes_read = read(fd_from, buf, BUF_SIZE);
	if (bytes_read == -1)
		exit_prog("Error: Can't read from file %s\n", from_path, 98, fd_from, fd_to);
	return (bytes_read);
}

/**
 * call_write - executes write sequence
 * @fd_from: fd for input file
 * @fd_to: fd for output file
 * @path: output filename
 * @buf: pointer to the buffer
 * @b: bytes to be written
 *
 * Return: bytes written
 */
ssize_t call_write(int fd_from, int fd_to, char *path, char *buf, ssize_t b)
{
	ssize_t bytes_written;

	bytes_written = write(fd_to, buf, b);
	if (bytes_written != b)
		exit_prog("Error: Can't write to %s\n", path, 99, fd_from, fd_to);

	return (bytes_written);
}

/**
 * main - start point
 * @argc: number of arguments
 * @argv: argument list
 *
 * Return: 0 (success) , 98 | 99 | 100 (fail)
 *
 * Description: copies data from one file to another
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char *file_from, *file_to;
	char buf[BUF_SIZE];
	size_t mode;
	ssize_t bytes_read;

	if (argc != 3)
		exit_prog("Usage: cp file_from file_to\n", NULL, 97, 0, 0);

	file_from = strdup(argv[1]);
	file_to = strdup(argv[2]);

	if (!file_from || access(file_from, F_OK | R_OK) != 0)
		exit_prog("Error: Can't read from file %s\n", file_from, 98, 0, 0);

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		exit_prog("Error: Can't read from file %s\n", file_from, 98, 0, 0);

	(access(file_to, F_OK) == 0) ? (mode = 0) : (mode = 0664);
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
		exit_prog("Error: Can't write to %s\n", file_to, 99, fd_from, 0);

	while (1)
	{
		bytes_read = call_read(fd_from, fd_to, file_from, buf);
		if (bytes_read <= 0)
			break;
		call_write(fd_from, fd_to, file_to, buf, bytes_read);
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
