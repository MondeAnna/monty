#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 1024
#define CMD_ONLY 1
#define CMD_VALUE 2
#define DELIM " \n"
#define NULL_BYTE '\0'

typedef struct cmd_s {
	char *cmd;
	char *value;
} cmd_t;




/**
 * _nchar - count number of occurances of char in string
 * @str: string
 * @char_: character
 * Return: number of occurances (short int)
 */
short int _nchar(char *str, char char_)
{
	short int n;

	if (!(*str))
		return (0);

	n = *str == char_ ? 1 : 0;

	return (n + _nchar(++str, char_));
}



cmd_t *init_cmd()
{
    cmd_t *cmd = malloc(sizeof(cmd_t));

    cmd->cmd = NULL;
    cmd->value = NULL;

    return (cmd);
}





/**
 * cmd_split - create array of arguemnts from user command
 * @line: command line input
 * Return: pointer to command-value pari (cmd_t *)
 */
cmd_t *cmd_split(char *line)
{
    cmd_t *cmd = init_cmd();;
	int argc;

	argc = _nchar(line, ' ') ? CMD_VALUE : CMD_ONLY;

	cmd->cmd = strtok(line, DELIM);
	cmd->value = argc == CMD_VALUE ? strtok(NULL, DELIM) : NULL;

	return (cmd);
}


size_t _strstrp(char *out, size_t len, const char *str)
{
	const char *end;
	size_t out_size, stripped_len;

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

	stripped_len = (size_t) (end - str);
	out_size = stripped_len < len-1 ? stripped_len : len-1;

	memcpy(out, str, out_size);

	out[out_size] = 0;

	return (out_size);
}

int main(void)
{
	FILE *file = fopen("bytecodes/05.m", "r");

	char stripped[BUFF];
	char *line = NULL;
	cmd_t *cmd = NULL;
	size_t size;

	while (getline(&line, &size, file) != EOF)
	{
	    _strstrp(stripped, size, line);
	    cmd = cmd_split(stripped);

	    printf("Unalterd:\t%s", line);
        printf("Stripped:\t%s\n\n\n", stripped);
	}

	free(line);

	if (file)
    	fclose(file);

	return (0);
}
