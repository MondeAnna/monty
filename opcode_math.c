#include "monty.h"

/**
 * opcode_add - add top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't add, stack too short";
	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error, *stack, line_number);

	head = *stack;
	next = head->next;

	next->n += head->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_div - div top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	char *error_size = "L%d: can't div, stack too short\n";
	char *error_zero_div = "L%d: division by zero\n";

	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error_size, *stack, line_number);

	head = *stack;
	next = head->next;

	if (!head->n)
		opcode_exit(error_zero_div, *stack, line_number);

	next->n -= head->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_mod - mod top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	char *error_size = "L%d: can't mod, stack too short\n";
	char *error_zero_div = "L%d: division by zero\n";

	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error_size, *stack, line_number);

	head = *stack;
	next = head->next;

	if (!head->n)
		opcode_exit(error_zero_div, *stack, line_number);

	next->n %= head->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_mul - mul top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't mul, stack too short";
	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error, *stack, line_number);

	head = *stack;
	next = head->next;

	next->n *= head->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_sub - sub top two nodes
 * @stack: stack
 * @line_number: bytecode line number
 * Return: void
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	char *error = "L%d: can't sub, stack too short";
	stack_t *head;
	stack_t *next;

	if (stack_size(*stack) < 2)
		opcode_exit(error, *stack, line_number);

	head = *stack;
	next = head->next;

	next->n -= head->n;
	opcode_pop(stack, line_number);
}
