#include "monty.h"

/**
 * _isdigit - discern if char is digit
 * @c: character being checked
 * Return: 1 if true, else zero
 */
int _isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

/**
 * _ensure_valid_value - checks that file can be opened
 * @value: value to be added to new node
 * @stack: stack to be pushed onto
 * Return: void
 */
void _ensure_valid_value(char *value, stack_t *stack)
{
	int is_digit = 0;

	while (*value)
		is_digit = _isdigit(*value++);

	if (is_digit)
		return;

	fprintf(stderr, "L%d: usage: push integer", cmd->line_number);

	free_stack(stack);
	cmd_empty(cmd);

	exit(EXIT_FAILURE);
}

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

	_ensure_valid_value(cmd->value, *stack);

	if (!node)
		return;

	node->n = atoi(cmd->value);
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
