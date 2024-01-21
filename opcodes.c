#include "monty.h"

/**
 * _isdigit - discern if char is digit
 * @c: character being checked
 * Return: 1 if true, else zero
 */
int _isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

/**
 * _ensure_valid_value - checks that file can be opened
 * @value: value to be added to new node
 * @stack: stack to be pushed onto
 * @line_number: line number in bytecode
 * Return: void
 */
void _ensure_valid_value(char *value, stack_t *stack, unsigned int line_number)
{
	int is_digit = 0;

	value = *value == '-' ? value + 1 : value;

	while (*value)
		is_digit = _isdigit(*value++);

	if (is_digit)
		return;

	fprintf(stderr, "L%d: usage: push integer", line_number);

	cmd_release(cmd);
	free_stack(stack);

	exit(EXIT_FAILURE);
}

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
 * opcode_pint - stack printing opcode
 * @stack: head of stack
 * @line_number: number of lines in stack when called
 * Return: void
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * opcode_push - adds to stack
 * @stack: head of stack
 * @line_number: number of line
 * Return: void
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *node;

	(void) line_number;
	node = malloc(sizeof(head));

	_ensure_valid_value(cmd->value, head, line_number);

	if (!node)
		return;

	node->n = atoi(cmd->value);
	node->next = head;
	node->prev = NULL;

	if (!head)
	{
		*stack = node;
		return;
	}

	head->prev = node;
	*stack = node;
}
