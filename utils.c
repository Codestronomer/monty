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
