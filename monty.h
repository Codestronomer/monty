#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	struct stack_s *prev;
	struct stack_s *next;
	int n;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int  line_number);
} instruction_t;


/**
 * struct globals - global structure to use in functions
 * @line: current line
 * @fifo: if stack or queue
 * @args: arguments
 * @fd: file descriptor
 * @head: head of doubly linked list
 * @current_line: current line
 *
 * Description: global structure for stack, queues
 * LIFO, FIFO ALX SE project
 */
typedef struct globals
{
	char *buffer;
	int fifo;
	char *arg;
	stack_t *head;
	FILE *fd;
	int current_line;
} global_t;


/* opcode instructions functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_Number);
void _pint(stack_t **stack, unsigned int cur_line);
void _pop(stack_t **stack, unsigned int line_nubmeer);

/* get opcodes function */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

extern global_t data;


/* doubly linked list functions */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_stack(stack_t *stack);


/* progam utility functions */
char *parse_line(char *line); 
#endif
