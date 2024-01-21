#include "monty.h"

/**
 * opcode_mul - mul top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't mul, stack too short";
	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error, *stack, line_number);

	head = *stack;
	next = head->next;

	next->n *= head->n;
	opcode_pop(stack, line_number);
}
