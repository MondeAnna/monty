#ifndef STACKS_AND_QUEUES_H
#define STACKS_AND_QUEUES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t\r\n\a"
#define NULL_BYTE 1
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

void ensure_two_cli_args(int argc);
FILE *_open(char *file_name);
void _read(FILE *file);
stack_t *stack_add(stack_t **head, const int n);
size_t stack_print(const stack_t *h);

#endif  /* STACKS_AND_QUEUES_H */
