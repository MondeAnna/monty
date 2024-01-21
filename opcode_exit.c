#include "monty.h"

/**
 * opcode_exit - exit during opcode execution
 * @error: error message
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_exit(char *error, stack_t *stack, unsigned int line_number)
{
	fprintf(stderr, error, line_number);
	cmd_release(cmd);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
