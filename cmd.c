#include "monty.h"

/**
 * cmd_init - initializes cmd object
 * Return: pointer to cmd object (cmd_t *)
 */
cmd_t *cmd_init()
{
	cmd_t *cmd = malloc(sizeof(cmd_t));

	if (!cmd)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	cmd->file = NULL;
	cmd->opcode = NULL;
	cmd->value = NULL;
	cmd->line_raw = NULL;
	cmd->line_stripped = NULL;

	cmd->line_number = 0;

	return (cmd);
}

/**
 * cmd_run - run provided bytecode file
 * @file_name: name of bytecode file
 * @cmd: cmb obj
 * @stack: head to stack
 * Return: void
 */
void cmd_run(char *file_name, cmd_t *cmd, stack_t *stack)
{
	size_t size = 0;

	cmd->file = fopen(file_name, "r");

	while (getline(&(cmd->line_raw), &size, cmd->file) != EOF)
	{
		(void) stack;
		puts(cmd->line_raw);
	}
}
