#include "monty.h"

/**
 * _cmd_exit_unknown_opcode - raised when erronous opcode given
 * @cmd: cmd object
 * @stack: head of stack
 * Return: void
 */
void _cmd_exit_unknown_opcode(cmd_t *cmd, stack_t **stack)
{
	fprintf(
		stderr,
		"L%d: unknown instruction %s\n",
		cmd->line_number,
		cmd->opcode
	);

	fclose(cmd->file);

	free(cmd->line_raw);
	free(cmd->line_stripped);

	(void) stack;

	exit(EXIT_FAILURE);
}

/**
 * _cmd_nchar - count number of occurances of char in string
 * @str: string
 * @char_: character
 * Return: number of occurances (short int)
 */
short int _cmd_nchar(char *str, char char_)
{
	/* consider replacing this with strchr */
	short int n;

	if (!(*str))
		return (0);

	n = *str == char_ ? 1 : 0;

	return (n + _cmd_nchar(++str, char_));
}

/**
 * _cmd_strstrp - strip whitespace from string
 * @dest: destination string
 * @src: source string
 * Return: lenght of stripped string (size_t)
 */
size_t _cmd_strstrp(char *dest, const char *src)
{
	size_t len = strlen(src);
	size_t dest_size, stripped_len;
	const char *end = src + len - 1;

	if (*src)
		return (0);

	while (isspace((unsigned char) *src))
		src++;

	if (!(*src))
	{
		*dest = *src;
		return (len);
	}

	while (end > src && isspace((unsigned char) *end))
		end--;

	end++;

	stripped_len = (size_t) (end - src);
	dest_size = stripped_len < len - 1 ? stripped_len : len - 1;

	memcpy(dest, src, dest_size);

	dest[dest_size] = 0;

	return (dest_size);
}
