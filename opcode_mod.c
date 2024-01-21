#include "monty.h"

/**
 * opcode_mod - mod top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	char *error_size = "L%d: can't mod, stack too short\n";
	char *error_zero_div = "L%d: division by zero\n";

	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error_size, *stack, line_number);

	head = *stack;
	next = head->next;

	if (!head->n)
		opcode_exit(error_zero_div, *stack, line_number);

	next->n %= head->n;
	opcode_pop(stack, line_number);
}
