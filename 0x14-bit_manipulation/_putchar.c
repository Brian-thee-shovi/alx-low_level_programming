#include <unistd.h>

/**
 * _putchar -this prints the character c to stdout in this code
 * @c: this the character to print in this code
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
