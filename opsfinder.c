#include "monty.h"
/**
 * opsfinder - will find the correct function for command
 * Return: working function
 */
void (*opsfinder(void))(stack_t **, unsigned int)
{
	inst_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i = 0;
	int x = 0;
	int GetOpcode, OpcodeLen;

	while (ops[i].opcode)
	{
		x = 0;
		GetOpcode = 1;
		OpcodeLen = strlen(ops[i].opcode);
		while (x < OpcodeLen)
		{
			if (ops[i].opcode[x] != buff[x])
			{
				GetOpcode = 0;
				break;
			}
			x++;
		}
		if (GetOpcode == 1 && (buff[x] == '\n'
		|| buff[x] == ' ' || buff[x] == '\0'))
			break;
		i++;
	}
	return (ops[i].f);
}
