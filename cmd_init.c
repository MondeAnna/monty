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
	cmd->line = NULL;
	cmd->opcode = NULL;
	cmd->value = NULL;
	cmd->line_number = 0;

	return (cmd);
}
