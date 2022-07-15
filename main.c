#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

global_t data;

/**
 * check_input - checks if inputted file exists and if file
 * can be opened
 * @argc: number of numbers
 * @argv: list of arguments
 *
 * Return: FILE struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point for the monty program
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	void (*f)(stack_t **stack, unsigned int line_number);
	size_t length = 0;
	int no_lines;
	char *opcode;

	fd = check_input(argc, argv);
	data.fd = fd;
	data.buffer = NULL;
	data.arg = NULL;
	data.current_line = 1;

	while ((no_lines = getline(&data.buffer, &length, data.fd)) != -1)
	{ 
		opcode = parse_line(data.buffer);
		if (opcode == NULL || opcode[0] == '#')
		{
			data.current_line++;
			continue;
		}

		f = get_opcodes(opcode);
		if (!f)
		{
			fprintf(stderr, "L%u: ", data.current_line);
			fprintf(stderr, "unknown instruction %s\n", opcode);
			free(data.buffer);
			free_stack(data.head);
			fclose(data.fd);
			exit(EXIT_FAILURE);
		}

		f(&data.head, data.current_line);
		data.current_line++;
	}

	free(data.buffer);
	free_stack(data.head);
	fclose(fd);

	return (EXIT_SUCCESS);
}
