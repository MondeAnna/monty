#include "monty.h"

/**
 * push - adds to stack
 * @stack: head of stack
 * @line_number: number of line
 * Return: void
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(*stack));

	if (!node)
		return;

	node->n = cmd->value;
	node->next = *stack;
	node->prev = NULL;

	if (!(*stack))
	{
		*stack = node;
		return;
	}

	(*stack)->prev = node;
	*stack = node;
}
