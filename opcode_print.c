#include "monty.h"

/**
 * _print - print doubly linked list
 * @h: head
 * Return: size of list (size_t)
 */
size_t _print(const stack_t *h)
{
	if (!h)
		return (0);

	printf("%d\n", h->n);

	return (1 + _print(h->next));
}

/**
 * opcode_pall - stack printing opcode
 * @stack: head of stack
 * @line_number: number of lines in stack when called
 * Return: void
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	_print(*stack);
}

/**
 * opcode_pchar - print char at top of stack
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	char *error_range = "L%d: can't pchar, value out of range\n";
	char *error_empty = "L%d: can't pchar, stack empty\n";

	stack_t *head = *stack;

	if (!head)
		opcode_exit(error_empty, *stack, line_number);

	if (!isascii(head->n))
		opcode_exit(error_range, *stack, line_number);

	printf("%c\n", head->n);
}

/**
 * opcode_pint - stack printing opcode
 * @stack: head of stack
 * @line_number: number of lines in stack when called
 * Return: void
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't pint, stack empty\n";

	if (!stack || !(*stack))
		opcode_exit(error, *stack, line_number);

	printf("%d\n", (*stack)->n);
}

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
