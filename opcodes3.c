#include "monty.h"

/**
 * monty_div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - computes the rest of the division of the second 
 * top element of the stack by the top element of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	monty_pop(stack, line_number);
}
