#include "monty.h"
/**
 * monty_push - pushes an element to the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!stack || !data_ptr->args[1] || !is_number(data_ptr->args[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(data_ptr->args[1]);
	add_dnodeint(stack, value);
}

/**
 * monty_pall - prints all the values on the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
