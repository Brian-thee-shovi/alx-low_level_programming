#include "main.h"

/**
 * create_file - this function that creates a file in this code
 * @filename: name of file being created in this code
 * @text_content: NULL terminated string to write to the
 * file in this code
 * Return:  1 for success, -1 for faillure and NULL
 * author: Brian .G
 */
int create_file(const char *filename, char *text_content)
{
	int by, v, max = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
	for (max = 0; text_content[max];)
	max++;
	}
by = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
v = write(by, text_content, max);
if (by == -1 || v == -1)
	return (-1);
close(by);
return (1);
}
