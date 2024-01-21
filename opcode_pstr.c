#include "monty.h"

/**
 * opcode_pstr - print str starting at top of stack
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;

	while (head)
	{
		if (!isascii(head->n) || !head->n)
			break;

		putchar(head->n);
		head = head->next;
	}

	putchar('\n');
}
