#include "monty.h"

/**
 * monty_push - pushes an element to the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!stack || !(data_ptr->args[1]) || !is_number(data_ptr->args[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(data_ptr->args[1]);
	if (data_ptr->topback == 1)
		add_dnodeint(stack, value);
	else if (data_ptr->topback == -1)
		add_dnodeint_end(stack, value);
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
	if (data_ptr->topback == 1)
		current = *stack;
	else if (data_ptr->topback == -1)
		current = (*stack)->next;

	while (current && current->n != 0)
	{
		printf("%d\n", current->n);
		if (data_ptr->topback == 1)
			current = current->next;
		else if (data_ptr->topback == -1)
			current = current->prev;
	}
}

/**
 * monty_pop - removes top elements from a stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tempnode;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tempnode = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(tempnode);
}

/**
 * monty_add - adds two element at the top of the stack
 * @stack: double pointer to stack
 * @line_number: line number
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node1 = *stack;
	node2 = (*stack)->next;

	node2->n += node1->n;
	*stack = node2;

	node2->prev = NULL;
	free(node1);
}

/**
 * monty_nop - do nothing in the stack
 * @stack: double pointer to stack
 * @line_number: line number
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
