#include "monty.h"

/**
 * opcode_pchar - print char at top of stack
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	char *error_range = "L%d: can't pchar, value out of range\n";
	char *error_empty = "L%d: can't pchar, stack empty\n";

	stack_t *head = *stack;

	if (!head)
		opcode_exit(error_empty, *stack, line_number);

	if (!isascii(head->n))
		opcode_exit(error_range, *stack, line_number);

	printf("%c\n", head->n);
}
