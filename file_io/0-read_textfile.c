#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * allocate_buffer - Allocates memory for the read buffer.
 * @letters: The number of letters to read.
 *
 * Return: Pointer to the allocated buffer, or NULL on failure.
 */
char *allocate_buffer(size_t letters)
{
	return (malloc(sizeof(char) * letters));
}

/**
 * read_textfile - Reads a text file and prints it
 * to POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: Actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char *buf;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = allocate_buffer(letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}
	n_read = read(fd, buf, letters);
	if (n_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	n_written = write(STDOUT_FILENO, buf, n_read);
	if (n_written == -1 || n_written != n_read)
	{
		free(buf);
		close(fd);
		return (0);
	}
	free(buf);
	close(fd);
	return (n_written);
}
