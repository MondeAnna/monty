#include "monty.h"

/**
 * stack_print - stack_print stack
 * @h: head
 * Return: size of list (size_t)
 */
size_t stack_print(const stack_t *h)
{
	if (!h)
		return (0);

	stack_printf("%d\n", h->n);

	return (1 + stack_print(h->next));
}
