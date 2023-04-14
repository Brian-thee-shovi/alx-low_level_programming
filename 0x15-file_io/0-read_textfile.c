#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: it texts the file being read
 * @letters: number of letters being read
 *
 * Return: the actual number of letters,0 if it fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *van;
	ssize_t g;
	ssize_t h;
	ssize_t r;

	g = open(filename, O_RDONLY);
	if (g == -1)
		return (0);
	van = malloc(sizeof(char) * letters);
	r = read(g, van, letters);
	h = write(STDOUT_FILENO, van, r);

	free(van);
	close(g);
	return (h);
}
