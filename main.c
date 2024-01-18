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
 * _exec - executes line
 * @line_args: args from file
 * Return: void
 */
void _exec(char **line_args)
{
	char *cmd;
	int value;

	value = 1;
	cmd = "extract cmd and value, then run";

	printf("%d %s\n", value, cmd);

	cmd = *line_args;
}

/**
 * _strnchr - count number of occurances of char in string
 * @str: string
 * @char_: character
 * Return: number of occurances (short int)
 */
short int _strnchr(char *str, char char_)
{
	short int count;

	if (!(*str))
		return (0);

	count = *str == char_ ? 1 : 0;

	return (count + _strnchr(++str, char_));
}

/**
 * _split - create array of arguemnts from user command
 * @line: command line input
 * Return: array of user command (char **)
 */
char **_split(char *line)
{
	char **args;
	char *arg;
	int argc;

	int index = 0;

	printf("%s", line);

	argc = _strnchr(line, ' ') + NULL_BYTE;

	printf("%d\n", argc);

	args = malloc(sizeof(*line) * argc);

	if (!args)
		exit(EXIT_FAILURE);

	arg = strtok(line, DELIM);

	while (arg)
	{
		argc = strlen(arg) + NULL_BYTE;
		args[index] = malloc(sizeof(*arg) * argc);
		args[index] = arg;
		arg = strtok(NULL, DELIM);
		index++;
	}

	args[index] = NULL;

	return (args);
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
	/* char *trimmed_line; */
	char *line;

	size_t len;

	while (getline(&line, &len, file) != EOF)
	{
		/* printf("%s", line); */
		/* printf("%s\n", _split(line)[0]); */
		/* printf("%s\n", _split(line)[1]); */
		/* trimmed_line = _trim(line); */

		/* tracker = _split(trimmed_line); */
		tracker = _split(line);
		tracker++;

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
