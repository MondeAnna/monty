#include "monty.h"

/**
 * _swap - swap integers
 * @a: left operand
 * @b: right operand
 * Return: void
 */
void _swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * _stack_size - get size of stack
 * @stack: head of stack
 * Return: size of stack (size_t)
 */
size_t _stack_size(stack_t *stack)
{
	if (!stack)
		return (0);
	return (1 + _stack_size(stack->next));
}

/**
 * opcode_swap - swap top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't swap, stack too short";
	stack_t *head;
	stack_t *next;

	if (_stack_size(*stack) < 2)
		opcode_exit(error, *stack, line_number);

	head = *stack;
	next = head->next;

	_swap(&head->n, &next->n);
}
