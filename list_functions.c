#include "monty.h"


/**
 * add_dnodeint - adds a new node at the beginning
 * of stack_t linked list
 * @head: head node of a stack_t linked list
 * @n: element of new node
 *
 * Return: Address of new element, exit on failure
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*head != NULL)
	{
		while ((*head)->prev != NULL)
			*head = (*head)->prev;
		(*head)->prev = new;
	}
	new->next = *head;

	*head = new;

	return (*head);
}


/**
 * add_dnodeint_end - adds a new node to the end of
 * stack_t doubly linked list
 * @head: head node of a stack_t linked list
 * @n: element to the added to new node
 *
 * Return: address of new node, exit on failure
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	if (*head != NULL)
	{
		while ((*head)->next != NULL)
			*head = (*head)->next;
		(*head)->next = new;
		new->prev = *head;
	}
	else
	{
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	return (new);
}


/**
 * free_stack - fress the stack
 *
 * @stack: top of the stack
 * Return: no return
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while ((tmp = stack) != NULL)
	{
		stack = stack->next;
		free(tmp);
	}
}
