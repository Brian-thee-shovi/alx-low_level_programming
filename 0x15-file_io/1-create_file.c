#include "main.h"

/**
 * create_file - It creates a file
 * @filename: this is the name of the file being created
 * @text_content: pointer to a string.
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int br, x, van = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (van = 0; text_content[van];)
			van++;
	}

	br = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(br, text_content, van);

	if (br == -1 || x == -1)
		return (-1);
	close(br);

	return (1);
}
