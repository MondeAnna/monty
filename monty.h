#ifndef STACKS_AND_QUEUES_H
#define STACKS_AND_QUEUES_H

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
 * struct cmd_s - command object
 * @file: file pointer
 * @opcode: user provided opcode
 * @value: user provided value
 * @line: parsed bytecode arg
 * @line_number: nth line in bytecode
 *
 * Description: command object carrying
 * bytecode related values
 */
typedef struct cmd_s {
	FILE *file;
	char *opcode;
	char *value;
	char *line;
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

/* will have to look into how to initialise this */
extern cmd_t cmd;

void cmd_exec(cmd_t *cmd, stack_t **stack);
cmd_t *cmd_init();
cmd_t *cmd_line_split(cmd_t *cmd);
void _ensure_file_access(char *file_name);
void exit_unknown_opcode(cmd_t *cmd, stack_t **stack);
void free_stack(stack_t *stack);
void pall(stack_t **stack, unsigned int line_number);
stack_t *stack_add(stack_t **head, const int n);
size_t _strstrp(char *dest, const char *src);

#endif  /* STACKS_AND_QUEUES_H */
