#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file in the code
 * @filename: pointer to the name of file in the code below
 * @text_content: string being added to the end of file in the code
 * Return: If the function fails or filename is NULL - -1.
 * author: Brian .G
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int by, v, maxx = 0;

	if (filename == NULL)
	return (-1);
	if (text_content != NULL)
	{
		for (maxx = 0; text_content[maxx];)
			maxx++;
	}
	by = open(filename, O_WRONLY | O_APPEND);
	v = write(by, text_content, maxx);
	if (by == -1 || v == -1)
		return (-1);
	close(by);
	return (1);
}

