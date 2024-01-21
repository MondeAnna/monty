#include "monty.h"

/**
 * opcode_sub - sub top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't sub, stack too short";
	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error, *stack, line_number);

	head = *stack;
	next = head->next;

	next->n -= head->n;
	opcode_pop(stack, line_number);
}
