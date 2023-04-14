#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - this allocates 1024 bytes for a buffer
 * @file: this is the name of the file
 *
 * Return: newly allocated buffer
 */
char *create_buffer(char *file)
{
	char *puky;

	puky = malloc(sizeof(char) * 1024);

	if (puky == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (puky);
}

/**
 * close_file -this closes the file descriptors
 * @fd: this is the file descriptor to be closed
 *
 */
void close_file(int fd)
{
	int k;

	k = close(fd);
	if (k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}

}

/**
 * main - this copies the content of one file to another file
 * @argc: this is number of arguments supplied to the program
 * @argv: this is an array to the arguments
 *
 * Return: 0 on success
 *
 * Description: if number of argument not the correct one, exit with code 97
 * if file_from does not exist, or if you can not read it, exit with code 98
 * if you can not create or if write to file_to fails, exit with code 99
 * if you can not close a file descriptor , exit with code 100
 */
int main(int argc, char *argv[])
{
	int br, van, h, k;
	char *puky;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	puky = create_buffer(argv[2]);
	br = open(argv[1], O_RDONLY);
	h = read(br, puky, 1024);
	van = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (br == -1 || h == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
			free(puky);
			exit(98);

		}

		k = write(van, puky, h);
		if (br == -1 || k == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
	free(puky);
	exit(99);
		}

		h = read(br, puky, 1024);
		van = open(argv[2], O_WRONLY | O_APPEND);

	} while (h > 0);

	free(puky);
	close_file(br);
	close_file(van);

	return (0);
}
