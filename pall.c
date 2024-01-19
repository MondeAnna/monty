#include "monty.h"

/**
 * _print - print doubly linked list
 * @h: head
 * Return: size of list (size_t)
 */
size_t _print(const stack_t *h)
{
	if (!h)
		return (0);

	printf("%d\n", h->n);

	return (1 + _print(h->next));
}

/**
 * pall - stack printing opcode
 * @stack: head of stack
 * @line_number: number of lines in stack when called
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	_print(*stack);
}

