#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITERS " \n"
#define NULL_BYTE '\0'

typedef struct cmd_s {
	char *cmd;
	char *value;
} cmd_t;

/**
 * _n_chars - count number of occurances of char in string
 * @str: string
 * @char_: character
 * Return: number of occurances (short int)
 */
short int _n_chars(char *str, char char_)
{
	short int n;

	if (!(*str))
		return (0);

	n = *str == char_ ? 1 : 0;

	return (n + _n_chars(++str, char_));
}

/**
 * cmd_split - create array of arguemnts from user command
 * @cmd: command line input
 * Return: array of user command (char **)
 */
char **cmd_split(char *cmd)
{
	char **args;
	char *arg;
	int argc;

	int index = 0;

	argc = _n_chars(cmd, ' ') + NULL_BYTE;
	args = malloc(sizeof(*cmd) * argc);

	if (!args)
		exit(EXIT_FAILURE);

	arg = strtok(cmd, DELIMITERS);

	while (arg)
	{
		argc = strlen(arg) + NULL_BYTE;
		args[index] = malloc(sizeof(*arg) * argc);
		args[index] = arg;
		arg = strtok(NULL, DELIMITERS);
		index++;
	}

	args[index] = NULL;

	return (args);
}

size_t trimwhitespace(char *out, size_t len, const char *str)
{
	const char *end;
	size_t out_size, trimmed_len;

	if(len == 0)
		return 0;


	while (isspace((unsigned char) *str))
		str++;

	if (!(*str))
	{
		*out = *str;
		return (1);
	}

	end = str + strlen(str) - 1;

	while (end > str && isspace((unsigned char) *end))
		end--;

	end++;

	trimmed_len = (size_t) (end - str);
	out_size = trimmed_len < len-1 ? trimmed_len : len-1;

	memcpy(out, str, out_size);

	out[out_size] = 0;

	return (out_size);
}

int main(void)
{
	FILE *file = fopen("../bytecodes/05.m", "r");

	char trimmed[1024];
	char *line;
	size_t size;

	while (getline(&line, &size, file) != EOF)
	{
	//	trimwhitespace(trimmed, size, line);

		puts(line);
	//	puts(trimmed);

	}
	puts("123");

	//free(line);
	fclose(file);

	puts("456");

	return (0);
}
