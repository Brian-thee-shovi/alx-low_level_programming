#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @index: Index of the node in the list
 * @next: pointer to the next node
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/*Prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
int binary_recursion(int *array, size_t left, size_t right, int value);
void print_array(int *array, size_t start, size_t end);
int binary_search2(int *array, size_t left, size_t right, int value);
int advanced_binary_recursive(int *array, size_t left, size_t right, int alue);
listint_t *jump_list(listint_t *list, size_t size, int value);

#endif /*SEARCH_ALGOS_H*/
