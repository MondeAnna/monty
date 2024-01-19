#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: head of stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *curr;

	if (!stack)
		return;

	while (stack->next)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}

	free(stack);
}

