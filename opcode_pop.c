#include "monty.h"

/**
 * opcode_pop - remote top element of stack
 * @stack: stack
 * @line_number: current line in bytecode
 * Return: void
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't pop an empty stack";
	stack_t *head = *stack;

	if (!head)
		opcode_exit(error, *stack, line_number);

	*stack = head->next;
	head->prev = NULL;

	free(head);
}
