#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * close_file - Safely closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file_content - Copies content from source to destination file descriptors.
 * @fd_from: The source file descriptor.
 * @fd_to: The destination file descriptor.
 * @argv: Argument vector for error messages.
 */
void copy_file_content(int fd_from, int fd_to, char *argv[])
{
	ssize_t n_read, n_written;
	char buf[1024];

	while ((n_read = read(fd_from, buf, 1024)) > 0)
	{
		n_written = write(fd_to, buf, n_read);
		if (n_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(fd_from);
			close_file(fd_to);
			exit(99);
		}
	}
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_file(fd_from);
		close_file(fd_to);
		exit(98);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(fd_from);
		exit(99);
	}
	copy_file_content(fd_from, fd_to, argv);
	close_file(fd_from);
	close_file(fd_to);
	return (0);
}
