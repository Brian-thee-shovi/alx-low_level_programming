#include "main.h"

/**
 * append_text_to_file - it appends text at the end of a file
 * @filename: this is the name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure or when the filename is NULL
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int br, x, van = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (van = 0; text_content[van];)
			van++;
	}

	br = open(filename, O_WRONLY | O_APPEND);
	x = write(br, text_content, van);

	if (br == -1 || x == -1)
		return (-1);

	close(br);

	return (1);
}
