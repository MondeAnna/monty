#include "monty.h"

/**
 * opcode_nop - does nothing
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
