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

	_cmd_exit_unknown_opcode(cmd, stack);
}

/**
 * cmd_init - initializes cmd object
 * Return: ptr to cmd object (cmd_t *)
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
 * cmd_line_split - set ptr to opcode and value embedded
 * in bytecode line
 * @cmd: cmd object
 * Return: ptr to command-value pari (cmd_t *)
 */
cmd_t *cmd_line_split(cmd_t *cmd)
{
	int argc = _cmd_nchar(cmd->line_raw, ' ') ? CMD_VALUE : CMD_ONLY;

	cmd->opcode = strtok(cmd->line_raw, DELIM);
	cmd->value = argc == CMD_VALUE ? strtok(NULL, DELIM) : NULL;

	return (cmd);
}

/**
 * cmd_line_strip - set ptr to first non-whitespace in str
 * @cmd: string from which whitespace is to be stripped
 * Return: ptr to command-value pari (cmd_t *)
 */
cmd_t *cmd_line_strip(cmd_t *cmd)
{
	cmd->line_stripped = malloc(*(cmd->line_raw) * strlen(cmd->line_raw));

	if (!cmd->line_stripped)
		return (cmd);

	_cmd_strstrp(cmd->line_stripped, cmd->line_raw);
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
		cmd = cmd_line_strip(cmd);
		cmd = cmd_line_split(cmd);
		cmd->line_number++;
		cmd_exec(cmd, &stack);
	}
}
