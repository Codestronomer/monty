#include "monty.h"

/**
 * _pint - prints the value at the top of
 * the stack, followed by a new line
 * @stack - top of stack implemented with
 * a doubly linked list
 * @cur_line - current line
 *
 * Return: Always nothing
 */

void _pint(stack_t **stack, unsigned int cur_line)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: ", cur_line);
		fprintf(stderr, "can't pint, stack empty\n");
	}
	else
	{
		printf("%d\n", tmp->n);
	}
}
