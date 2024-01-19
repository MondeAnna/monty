#include "monty.h"

/**
 * cmd_exec - executes opcode
 * @cmd: cmd object
 * @stack: head of stack
 * Return: void
 */
void cmd_exec(cmd_t *cmd, stack_t **stack)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	int i = 0;

	while (opcodes[i].opcode)
	{
		if (!strcmp(cmd->opcode, opcodes[i].opcode))
			break;
		i++;
	}

	if (opcodes[i].opcode)
	{
		opcodes[i].f(stack, cmd->line_number);
		return;
	}

	_exit_unknown_opcode(cmd, stack);
}
