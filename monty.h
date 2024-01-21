#ifndef STACKS_AND_QUEUES_H
#define STACKS_AND_QUEUES_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_ONLY 1
#define CMD_VALUE 2
#define DELIM " \n"

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
 * struct cmd_s - command object
 * @file: file ptr
 * @opcode: user provided opcode
 * @value: user provided value
 * @line_raw: unaltered ptr to parsed bytecode arg
 * @line_stripped: ptr to 1st non-whitespace of `line_raw`
 * @line_number: nth line in bytecode
 *
 * Description: command object carrying bytecode
 * related values
 */
typedef struct cmd_s {
	FILE *file;
	char *opcode;
	char *value;
	char *line_raw;
	char *line_stripped;
	unsigned int line_number;
} cmd_t;

extern cmd_t *cmd;

cmd_t *cmd_init();
cmd_t *cmd_line_proc(cmd_t *cmd);
void cmd_release(cmd_t *cmd);
void cmd_run(char *file_name, cmd_t *cmd, stack_t *stack);

void ensure_file_access(char *file_name);
void free_stack(stack_t *stack);
char *get_file_name(int argc, char **argv);
size_t stack_size(stack_t *stack);

void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_exit(char *error, stack_t *stack, unsigned int line_number);
void opcode_nop(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_sub(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);

#endif  /* STACKS_AND_QUEUES_H */
