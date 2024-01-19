#include "monty.h"

/**
 * _ensure_file_access - checks that file can be opened
 * @file_name: name of file
 * Return: void
 */
void _ensure_file_access(char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (file)
		return;

	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}

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
 * get_line_count - number of lines in file
 * @file_name: name of file
 * Return: line count
 */
int get_line_count(char *file_name)
{
	FILE *file = fopen(file_name, "r");
	int count = 1;
	int n;

	while (!feof(file))
	{
		n = fgetc(file);

		if (n == '\n')
			count++;
	}

	fclose(file);
	return (count);
}

/**
 * get_mapped_args - map arguments from bytecode
 * @file_name: name of file
 * @line_count: number of lines in file
 * Return: pointer to mapping (char **)
 */
char **get_mapped_args(char *file_name, int line_count)
{
	char **args = malloc(sizeof(char **) * line_count + 1);

	_read(file_name, args);

	puts("asdf");

	/* while (line_count--) */
		/* puts(args[line_count]); */

	puts("asdf");
	return (args);
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
	/* char **mapped_args; */
	int line_count;

	_ensure_file_access(file_name);

	line_count = get_line_count(file_name);
	get_mapped_args(file_name, line_count);

	/* mapped_args = get_mapped_args(file_name, line_count); */
	/* printf("%s\n", *mapped_args); */
	/* _read(file_name); */
	/* fclose(file); */

	return (EXIT_SUCCESS);
}
