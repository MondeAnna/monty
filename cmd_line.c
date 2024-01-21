#include "monty.h"

/**
 * _cmd_line_nchar - count number of occurances of char in string
 * @str: string
 * @char_: character
 * Return: number of occurances (short int)
 */
short int _cmd_line_nchar(char *str, char char_)
{
	/* consider replacing this with strchr */
	short int n;

	if (!(*str))
		return (0);

	n = *str == char_ ? 1 : 0;

	return (n + _cmd_line_nchar(++str, char_));
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
/**
 * _cmd_line_split - set ptr to opcode and value embedded
 * in bytecode line
 * @cmd: cmd object
 * Return: ptr to command-value pari (cmd_t *)
 */
cmd_t *_cmd_line_split(cmd_t *cmd)
{
	int argc = _cmd_line_nchar(cmd->line_raw, ' ') ? CMD_VALUE : CMD_ONLY;

	cmd->opcode = strtok(cmd->line_raw, DELIM);
	cmd->value = argc == CMD_VALUE ? strtok(NULL, DELIM) : NULL;

	return (cmd);
}

/**
 * _cmd_line_strip - set ptr to first non-whitespace in str
 * @cmd: string from which whitespace is to be stripped
 * Return: ptr to command-value pari (cmd_t *)
 */
cmd_t *_cmd_line_strip(cmd_t *cmd)
{
	cmd->line_stripped = malloc(*(cmd->line_raw) * strlen(cmd->line_raw));

	if (!cmd->line_stripped)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	_cmd_strstrp(cmd->line_stripped, cmd->line_raw);
	return (cmd);
}

/**
 * cmd_line_proc - set ptr to opcode and value embedded
 * in bytecode line
 * @cmd: cmd object
 * Return: ptr to command-value pari (cmd_t *)
 */
cmd_t *cmd_line_proc(cmd_t *cmd)
{
	cmd = _cmd_line_split(cmd);
	cmd = _cmd_line_strip(cmd);
	return (cmd);
}
