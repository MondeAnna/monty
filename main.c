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

	ensure_file_access(file_name);
	cmd = cmd_init();

	printf("cmd line number: %d\n", cmd->line_number);

	return (EXIT_SUCCESS);
}
