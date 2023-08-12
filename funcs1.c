#include "monty.h"
/**
 * push - adds a new node to the stack
 * @stack: linked list
 * @line_number: line number in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char **newBUFF;
	int num;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free(new);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newBUFF = splitter(buff, " ");

	num = _atoi(newBUFF[1], line_number);

	new->n = num;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;
	*stack = new;
	free(newBUFF);
}

/**
 * pop - removes the element at the top of the stack
 * @stack: linked list of nodes
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *rm = *stack;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		*stack = rm->next;
		(*stack)->prev = NULL;
		free(rm);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - swaps places of the top two elements in the stack
 * @stack: linked list of nodes
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp = *stack;

	if (!*stack || !stack || !head->next)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	head->prev = NULL;

	temp->next = head->next;
	head->next = temp;
	(head->next)->prev = head;

	*stack = head;
}

/**
 * add - adds the values of the top two elements in the stack
 * @stack: linked list of nodes
 * @line_number: line nuumber
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!*stack || !stack || !head->next)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(head->next)->n += head->n;

	pop(&head, line_number);

	*stack = head;
}
