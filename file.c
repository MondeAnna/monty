#include "monty.h"

/**
 * ensure_file_access - checks that file can be opened
 * @file_name: name of file
 * Return: void
 */
void ensure_file_access(char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	fclose(file);
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
