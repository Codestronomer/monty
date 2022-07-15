#include "monty.h"

/**
 * _push - The opcode pushes an element to the stack
 * @stack: head of a doubly linked list
 * @line_number:  line number
 *
 * return: Always nothing;
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int i, n;

	if (!data.arg)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_stack(data.head);
		fclose(data.fd);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.arg[i] != '\0'; i++)
	{
		if (!isdigit(data.arg[i]))
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_stack(data.head);
			fclose(data.fd);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(data.arg);
	add_dnodeint(stack, n);
}


/**
 * _pall - prints all values on the stack from the top
 * @stack: head of a doubly linked list
 * @line_number: line number
 *
 * Return: Always nothing
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
