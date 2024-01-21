#include "monty.h"

/**
 * opcode_pint - stack printing opcode
 * @stack: head of stack
 * @line_number: number of lines in stack when called
 * Return: void
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't pint, stack empty\n";

	if (!stack || !(*stack))
		opcode_exit(error, *stack, line_number);

	printf("%d\n", (*stack)->n);
}
