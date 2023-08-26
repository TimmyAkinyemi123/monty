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

/**
 * monty_pchar - prints the char at the top of the stack
 * followed by a new line.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int character = (*stack)->n;
	stack_t *tempnode = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (character < 0 || character > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(character);
	putchar('\n');

	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(tempnode);
}

/**
 * monty_pstr - prints the string starting at the top of the stack
 * followed by a new line.
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tempnode = *stack;
	(void)line_number;

	while (tempnode && tempnode->n > 0 && tempnode->n < 128)
	{
		printf("%c", tempnode->n);
		tempnode = tempnode->next;
	}
	printf("\n");
}
