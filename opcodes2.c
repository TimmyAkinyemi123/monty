#include "monty.h"

/**
 * monty_swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;

	if (second->next)
		second->next->prev = first;
	first->next = second->next;

	second->next = first;
	first->prev = second;

	*stack = second;
}

/**
 * monty_pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * monty_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_rotl - Rotates the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number currently being interpreted
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *last = NULL;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	first = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	first->prev = last;
	last->next = first;
	first->next = NULL;
}
