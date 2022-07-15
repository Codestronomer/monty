#include "monty.h"

/**
 * get_opcodes - select correct function to perform
 * operation
 * @opc: character containing opcode
 *
 * Return: NULL on failure, pointer to function on SUCCESS
 */

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opc) == 0)
			return (instructions[i].f);
	}
	return (NULL);
}
