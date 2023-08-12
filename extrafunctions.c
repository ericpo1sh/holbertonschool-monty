#include "monty.h"
/**
 * free_list - frees the whole linked list (with stack)
 * @head: head node of the linked list.
 */
void free_list(stack_t *head)
{
	stack_t *stack;

	while (head)
	{
		stack = head->next;
		free(head);
		head = stack;
	}
}

/**
 * _calloc - will set bytes of allocation to 0
 * @nmemb : the size of our array
 * @size : the size in bytes
 * Return: Null if segfualt, p if success
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;

	if (nmemb == 0)
		return (NULL);

	if (size == 0)
		return (NULL);

	p = malloc(nmemb * size);

	if (p == NULL)
		return (NULL);

	memset(p, 0, nmemb * size);

	return (p);
}
/**
 * splitter - splits the string in order to tokenize it
 * @str: string input
 * @delim: deliminator
 * Return: separated string
 */
char **splitter(char *str, char *delim)
{
	char *temp, **splitstring;
	int i = 0;

	temp = strtok(str, delim);
	splitstring = (char **)_calloc(100, sizeof(char *));

	if (!splitstring)
	{
		free(splitstring);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		splitstring[i] = temp;
		temp = strtok(NULL, delim);
		i++;
	}
	return (splitstring);
}

/**
 * _atoi - custom atoi that takes in two parameters, and converts into int
 * @str: string input
 * @line_number: line number
 * Return: result
 */
int _atoi(char *str, unsigned int line_number)
{
	int num = 0;
	int i = 0;
	unsigned int accnums = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		accnums++;
		i++;
	}

	if (accnums != strlen(str) - 1)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (num);
}
