#include "monty.h"


/**
 * _read - read file
 * @file_name: name of file
 * @args: pointer to file's line values
 * Return: pointer to file's line values
 */
char **_read(char *file_name, char **args)
{
	FILE *file = fopen(file_name, "r");

	char **tracker = args;
	char *trimmed_line;
	char *line;

	size_t len;

	while (getline(&line, &len, file) != EOF)
	{
		cmd_split(line);
		/* printf("%s", line); */

		/* printf("%s\n", _split(line)[0]); */
		/* printf("%s\n", _split(line)[1]); */
		trimmed_line = _trim(line);

		tracker = _split(trimmed_line);

		/* tracker = _split(line); */
		tracker++;
		break;

		/* see if we have to free trimmed_line */

		/* remember to remove this */
		/* _exec(line_args); */
	}

	free(line);

	return (args);
}

/**
 * get_file_name - ensure 2 values are passed
 * @argc: number of cli arguments
 * @argv: cli arguments
 * Return: file name (char *)
 */
char *get_file_name(int argc, char **argv)
{
	if (argc == 2)
		return (argv[1]);
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *file_name = get_file_name(argc, argv);
	cmd_t *cmd = init_cmd();
	stack_t *stack = NULL;

	char stripped[BUFF];
	size_t size = 0;

	_ensure_file_access(file_name);
	cmd->file = fopen(filename, "r");

	while (getline(&(cmd->line), &size, cmd->file) != EOF)
	{
		_strstrp(stripped, size, cmd->line);

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
