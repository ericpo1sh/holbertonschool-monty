#include "monty.h"
/**
 * file_handler - reads through file and linkes with corresponding functions
 * @file: file to be translated
 */
void file_handler(char *file)
{
	FILE *fd;
	size_t size = 0;
	int line_n = 1;
	stack_t *head;
	void (*opcode_func)(stack_t **, unsigned int);

	fd = fopen(file, "r+");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	head = NULL;
	while (getline(&buff, &size, fd) != -1)
	{
		opcode_func = opsfinder();
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s", line_n, buff);
			exit(EXIT_FAILURE);
		}
		opcode_func(&head, line_n);
		line_n++;
	}
	free(buff);
	free_list(head);
	fclose(fd);
}
