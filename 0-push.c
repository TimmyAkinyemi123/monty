#include "monty.h"

/**
 * push_it - insert new element in a C stack
 * @stack: double pointer to a linked list
 * @line_number: value
 * Return: no value
 */
void push_it(stack_t **stack, unsigned int line_number)
{
	int element, idx;

	if (varb.argmt != NULL)
	{
		dprintf(2, "L%u: ", line_number); /* L<line_number>: */
		dprintf(2, "usage: push integer");
		exit(EXIT_FAILURE);
	}

	for (idx = 0; varb.argmt[idx] != '\0'; idx++)
	{
		if (!isdigit(varb.argmt[idx] && varb.argmt[idx] != '-'))
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			exit(EXIT_FAILURE);
		}
	}

	element = atoi(varb.argmt);
	if (varb.topback == 1)
		add_dnodeint(stack, element);
	else
		add_dnodeint_end(stack, element);
}

/**
 * pop_it - remove top element from a C stack
 * @stack: double pointer to linked list
 * @line_number: value
 * Return: no value
 */
void pop_it(stack_t **stack, unsigned int line_number)
{
	stack_t *tempnode;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tempnode = *stack;
	*stack = (*stack)->next;
	free(tempnode);
}
