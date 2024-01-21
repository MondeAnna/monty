#include "monty.h"

/**
 * cmd_exit - raised when erronous opcode given
 * @cmd: cmd object
 * @stack: head of stack
 * Return: void
 */
void _cmd_exit(cmd_t *cmd, stack_t **stack)
{
	fprintf(
		stderr,
		"L%d: unknown instruction %s\n",
		cmd->line_number,
		cmd->opcode
	);

	cmd_release(cmd);
	free_stack(*stack);

	exit(EXIT_FAILURE);
}

/**
 * _cmd_exec - executes opcode
 * @cmd: cmd object
 * @stack: head of stack
 * Return: void
 */
void _cmd_exec(cmd_t *cmd, stack_t **stack)
{
	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
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

	_cmd_exit(cmd, stack);
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
		cmd = cmd_line_proc(cmd);
		cmd->line_number++;
		_cmd_exec(cmd, &stack);
	}
}