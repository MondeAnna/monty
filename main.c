#include "monty.h"

/**
 * check_cli_args - ensure 2 values are passed
 * @argc: number of cli arguments
 * Return: void
 */
void check_cli_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
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

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	return (file);
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

	check_cli_args(argc);

	file = _open(argv[1]);

	fclose(file);

	return (EXIT_SUCCESS);
}
