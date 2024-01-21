#include "monty.h"

/**
 * opcode_pint - stack printing opcode
 * @stack: head of stack
 * @line_number: number of lines in stack when called
 * Return: void
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
