#include "main.h"
#include <stdlib.h>

/**
 * argstostr - links all the arguments of your program.
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: a pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
char *str, *s;
int y, x, z, len = 0;

if (ac == 0 || av == NULL)
return (NULL);

for (y = 0; y < ac; y++)
{
s = av[y];
x = 0;

while (s[x++])
len++;
len++;
}

str = (char *)malloc(sizeof(char) * (len + 1));
if (str == NULL)
return (NULL);

for (y = 0, x = 0; y < ac && x < len; y++)
{
s = av[y];
z = 0;

while (s[z])
{
str[x] = s[z];
z++;
x++;
}
str[x++] = '\n';
}
str[x] = '\0';

return (str);
}
