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

#include "monty.h"

/**
 * stack_size - get size of stack
 * @stack: head of stack
 * Return: size of stack (size_t)
 */
size_t stack_size(stack_t *stack)
{
	if (!stack)
		return (0);
	return (1 + stack_size(stack->next));
}
