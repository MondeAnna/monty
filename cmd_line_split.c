#include "monty.h"

/**
 * _nchar - count number of occurances of char in string
 * @str: string
 * @char_: character
 * Return: number of occurances (short int)
 */
short int _nchar(char *str, char char_)
{
	/* consider replacing this with strchr */
	short int n;

	if (!(*str))
		return (0);

	n = *str == char_ ? 1 : 0;

	return (n + _nchar(++str, char_));
}

/**
 * cmd_line_split - create array of arguemnts from user command
 * @line: command line input
 * Return: pointer to command-value pari (cmd_t *)
 */
cmd_t *cmd_line_split(cmd_t *cmd)
{
	int argc = _nchar(cmd->line, ' ') ? CMD_VALUE : CMD_ONLY;

	cmd->opcode = strtok(cmd->line, DELIM);
	cmd->value = argc == CMD_VALUE ? strtok(NULL, DELIM) : NULL;


