#include "monty.h"

cmd_t *cmd = NULL;

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *file_name = get_file_name(argc, argv);
	stack_t *stack = NULL;

	ensure_file_access(file_name);

	cmd = cmd_init();
	cmd_run(file_name, cmd, stack);
	cmd_release(cmd);

	free_stack(stack);

	return (EXIT_SUCCESS);
}
