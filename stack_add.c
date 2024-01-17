#include "monty.h"

/**
 * stack_add - add to top of stack
 * @head: head
 * @n: data
 * Return: pointer to top of stack (stack_t)
 */
stack_t *stack_add(stack_t **head, const int n)
{
	stack_t *node;

	node = malloc(sizeof(*head));

	if (!node)
		return (*head);

	node->n = n;
	node->next = *head;
	node->prev = NULL;

	if (!(*head))
	{
		*head = node;
		return (*head);
	}

	(*head)->prev = node;
	*head = node;

	return (*head);
}
