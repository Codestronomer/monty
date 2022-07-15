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
		free_data();
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", tmp->n);
	}	
}


/**
 * _pop - removes the top element of the stack
 * @stack: head of stack implemented with a 
 * doubly linked list
 * @line_number: current line
 *
 * Return: always nothing
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pop an empty stack\n");
		free_data();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

