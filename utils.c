#include "monty.h"

/**
 * parse_line - parses the from buffer
 * @line: buffer
 *
 * Return: opcode, NULL on failure
 */

char *parse_line(char *line)
{
	char *arg;

	arg = strtok(line, " \t\n");
	if (arg == NULL)
		return (NULL);
	data.arg = strtok(NULL, "  \t\n");

	return (arg);
}


/**
 * free_data - frees the memory allocated to globals var
 *
 * Return: Always nothing
 */

void free_data(void)
{
	free(data.buffer);
	free_stack(data.head);
	fclose(data.fd);
}
