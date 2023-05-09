#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fo);

/**
 * cp - copies the content of a file to another file in the code
 * create_buffer - Allocates 1024 bytes for a buffer in the code
 * @file: name of the file where chars are being stored
 * Return: pointer to the allocated buffer in the code below
 * author: Brian .G
 */
char *create_buffer(char *file)
{
	char *nbuff;

	nbuff = malloc(sizeof(char) * 1024);
	if (nbuff == NULL)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't write to %s\n", file);
	exit(99);
	}
	return (nbuff);
}

/**
 * close_file - this closes file descriptors in code below
 * @fo: descriptor to be closed in the code below
 */
void close_file(int fo)
{
	int vi;

	vi = close((fo));
	if
	(vi == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fo %d\n", fo);
exit(100);
}
}

/**
 * main - copies content of a file to another in this code
 * @argc: number of arguments supplied to the program in this code
 * @argv: array of pointer to the arguments in the code
 * Return: 0 on success
 *
*
*Description:
*i) if argument count wrong - exit code 97
*ii)  If file_from does not exist or cannot be read - exit code 98
*iii)If file_to cannot be created or written to - exit code 99
*iv) If file_to or file_from cannot be closed - exit code 100
*/
int main(int argc, char *argv[])
{
	int by, v, ty, x;
	char *buffer;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}
	buffer = create_buffer(argv[2]);
	by = open(argv[1], O_RDONLY);
	ty = read(by, buffer, 1024);
	 v = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
	if (by == -1 || ty == -1)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't read from file %s\n", argv[1]);
	free(buffer);
	exit(98);
	}
	x = write(v, buffer, ty);
	if (v == -1 || x == -1)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't write to %s\n", argv[2]);
	free(buffer);
	exit(99);
	}
	ty = read(by, buffer, 1024);
	v = open(argv[2], O_WRONLY | O_APPEND);
} while (ty > 0);
	 free(buffer);
	 close_file(by);
	 close_file(v);
return (0);
}

