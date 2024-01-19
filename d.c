#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 1024
#define CMD_ONLY 1
#define CMD_VALUE 2
#define DELIM " \n"
#define NULL_BYTE '\0'

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct cmd_s {
	char *opcode;
	char *value;
	int line_number;
} cmd_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


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

    cmd->opcode = NULL;
    cmd->value = NULL;
    cmd->line_number = 0;

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

	cmd->opcode = strtok(line, DELIM);
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

/**
 * print - print doubly linked list
 * @h: head
 * Return: size of list (size_t)
 */
size_t print(const stack_t *h)
{
	if (!h)
		return (0);

	printf("%d\n", h->n);

	return (1 + print(h->next));
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    print(*stack);
}

void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(*stack));

	if (!node)
		return;

	node->next = *stack;
	node->prev = NULL;

	if (!(*stack))
		*stack = node;
		return;

	(*stack)->prev = node;
	*stack = node;
}

void _exec(cmd_t *cmd, stack_t **stack)
{
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL},
    };

	int i = 0;

	while (opcodes[i].opcode)
	{
		if (!strcmp(cmd->opcode, opcodes[i].opcode))
			break;
		i++;
	}

    opcodes[i].f(stack, cmd->line_number);
}

void free_stack(stack_t *head)
{
	stack_t *curr;

	if (!head)
		return;

	while (head->next)
	{
		curr = head;
		head = head->next;
		free(curr);
	}

	free(head);
}

int main(void)
{
	FILE *file = fopen("bytecodes/05.m", "r");

	char stripped[BUFF];
	char *line = NULL;
	cmd_t *cmd = NULL;
	size_t size = 0;
	int line_number = 0;
	stack_t *stack = NULL;

	while (getline(&line, &size, file) != EOF)
	{
	    _strstrp(stripped, size, line);

	    cmd = cmd_split(stripped);
	    cmd->line_number = ++line_number;

	    _exec(cmd, &stack);

	    printf("Unalterd:\t%s", line);
        printf("Stripped:\t%s\n\n", stripped);

        printf("Split Command:\t%s\n", cmd->opcode);
        printf("Split Value:\t%s\n\n\n", cmd->value);
	}

	free(line);
    free_stack(stack);

	if (file)
    	fclose(file);

	return (0);
}
