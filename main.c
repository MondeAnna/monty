#include "monty.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *file_name = get_file_name(argc, argv);
	cmd_t *cmd = cmd_init();
	stack_t *stack = NULL;

	char stripped[BUFF];
	size_t size = 0;

	_ensure_file_access(file_name);
	cmd->file = fopen(file_name, "r");

	while (getline(&(cmd->line), &size, cmd->file) != EOF)
	{
		_strstrp(stripped, cmd->line);

		cmd = cmd_line_split(cmd);
		cmd->line_number++;

		cmd_exec(cmd, &stack);
	}

	free(cmd->line);
	free_stack(stack);

	if (cmd->file)
	fclose(cmd->file);

	return (EXIT_SUCCESS);
}
