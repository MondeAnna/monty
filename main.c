#include "monty.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *script_name;

	if (argc != 2)
	{
		puts("please provide bytecode");
		return (EXIT_FAILURE);
	}

	script_name = argv[1];
	puts(script_name);

	return (EXIT_SUCCESS);
}
