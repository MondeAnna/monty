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
		{"push", opcode_push},
		{"pall", opcode_pall},
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

	cmd_exit(cmd, stack);
}

/**
 * cmd_exit - raised when erronous opcode given
 * @cmd: cmd object
 * @stack: head of stack
 * Return: void
 */
void cmd_exit(cmd_t *cmd, stack_t **stack)
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
 * cmd_line_proc - set ptr to opcode and value embedded
 * in bytecode line
 * @cmd: cmd object
 * Return: ptr to command-value pari (cmd_t *)
 */
cmd_t *cmd_line_proc(cmd_t *cmd)
{
	cmd = _cmd_line_split(cmd);
	cmd = _cmd_line_strip(cmd);
	return (cmd);
}

/**
 * cmd_release - releases cmd bound resources
 * @cmd - cmd object
 * Return: void
 */
void cmd_release(cmd_t *cmd)
{
	fclose(cmd->file);
	free(cmd->line_raw);
	free(cmd->line_stripped);
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
		cmd_exec(cmd, &stack);
	}
}
