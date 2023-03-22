#include "function_pointers.h"

/**
 * array_iterator -function that executes a function given as
 * a parameter on each element of an array.
 *
 * @array: array that function is executed on
 * @size:arrays size
 * @action: pointer to the function used
 *
 * Return :void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i;

if (array && action)
{
i = 0;
while (i < size)
{
action(array[i]);
i++;
}
}
}
