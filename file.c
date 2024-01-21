#include "monty.h"

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
