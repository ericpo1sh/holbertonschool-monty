#include "monty.h"
/**
 * main - checks if argc is valid, and sends file through handler function
 * @argc: arguement count
 * @argv: arguement vector (commands)
 * Return: EXIT_FAILURE if count not 2, 0 If success.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_handler(argv[1]);
	return (0);
}
