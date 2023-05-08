#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX
 * standard output in this code
 * @filename: this is the tx file read in the code below
 * @letters: number of letters being read in this code
 * Return: 0 when function fails or filename is NULL
 * author: Brian .G
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *mann;
	ssize_t by;
	ssize_t di;
	ssize_t vx;

	by = open(filename, O_RDONLY);
	if (by == -1)
		return (0);
	mann = malloc(sizeof(char) * letters);
	di = read(by, mann, letters);
	vx = write(STDOUT_FILENO, mann, di);
	free(mann);
	close(by);
	return (vx);
}
