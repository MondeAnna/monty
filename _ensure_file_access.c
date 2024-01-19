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
	{
		fclose(file);
		return;
	}

	fclose(file);
	fprintf(stderr, "Error: Can't open file %s\n", file_name);

	exit(EXIT_FAILURE);
}
