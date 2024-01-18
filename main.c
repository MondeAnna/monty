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
 * main - entry point
 * @argc: arg count
 * @argv: arg values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *script_name;

	check_cli_args(argc);

	script_name = argv[1];
	puts(script_name);

	return (EXIT_SUCCESS);
}
