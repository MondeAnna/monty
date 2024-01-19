#include "monty.h"

/**
 * exit_unknown_opcode - raised when erronous opcode given
 * @cmd: cmd object
 * @stack: head of stack
 * Return: void
 */
void exit_unknown_opcode(cmd_t *cmd, stack_t **stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", cmd->line_number, cmd->opcode);
	fclose(cmd->file);
	free(cmd->line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

