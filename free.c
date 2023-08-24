#include "monty.h"

/**
 * free_tokens - Frees memory allocated for tokenized arguments.
 * @data: program data
 */
void free_tokens(monty_data *data)
{
	char **args = data->args;
	int i = 0;

	if (args)
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
		data->args = NULL;
	}
}

/**
 * monty_stack - sets to stack
 * @stack: double pointer to stack
 * @line_number: line number
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data_ptr->topback = 1;
}

/**
 * monty_queue - sets to queue
 * @stack: double pointer to stack
 * @line_number: line number
 *
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data_ptr->topback = 0;
}
