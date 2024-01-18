#include "monty.h"

/**
 * ensure_two_cli_args - ensure 2 values are passed
 * @argc: number of cli arguments
 * Return: void
 */
void ensure_two_cli_args(int argc)
{
	if (argc == 2)
		return;
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * _open - open bytecode file
 * @file_name: name of file
 * Descriptioin: It is the responsibility of the
 * caller to close the file
 * Return: pointer to file
 */
FILE *_open(char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (file)
		return (file);

	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
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

	argc = _strnchr(line, ' ') + NULL_BYTE;
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
 * _nlines - number of lines in file
 * @file: file pointer
 * Descriptioin: It is the responsibility of the
 * caller to close the file
 * Return: line count
 */
int _nlines(FILE *file)
{	/*
	 * start passing file names so that the we
	 * can open and close within one func
	 */
	int count = 1;
	int n;

	while (!feof(file))
	{
		n = fgetc(file);
		if (n == '\n')
			count++;
	}

	return (count);
}

/**
 * _read - read file
 * @file: pointer to file
 * Return: void
 */
void _read(FILE *file)
{
	char **line_args;
	char *line;
	size_t len;

	while (getline(&line, &len, file) != EOF)
	{
		/* keep track of line count here */
		line_args = _split(line);
		printf("%d\n", _nlines(file));
		_exec(line_args);
	}

	free(line);
	free(line_args);
}

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *file;

	ensure_two_cli_args(argc);

	file = _open(argv[1]);
	_read(file);
	fclose(file);

	return (EXIT_SUCCESS);
}
