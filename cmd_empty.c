#include "monty.h"

/**
 * cmd_empty - clear resources bound to cmd
 * @cmd: cmd object
 * Description: close file stream, free the
 * current line carrying present opcode
 * Return: void
 */
void cmd_empty(cmd_t *cmd)
{
	fclose(cmd->file);

	/*
	 * cmd->opcode && cmd->line are
	 * subptrs of cmd-line
	 */
	free(cmd->line);
	exit(EXIT_FAILURE);
}

