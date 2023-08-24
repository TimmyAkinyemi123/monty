#include "monty.h"

/**
 * init_data - intializes monty program data
 * @data: monty program data
 */
void init_data(monty_data *data)
{
	data->line = NULL;
	data->line_num = 0;
	data->args = NULL;
	data->topback = 1;
}

/**
 * stack_init - initialize the stack pointer
 * @stack: double pointer to beginning of stack
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int stack_init(stack_t **stack)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		perror("Allocation error");
		return (EXIT_FAILURE);
	}
	temp->n = 0;
	temp->prev = NULL;
	temp->next = NULL;
	*stack = temp;

	return (EXIT_SUCCESS);
}

/**
 * is_opcode - checks if string is an opcode
 * @stack: double pointer to stack
 * @data: monty program data
 * Return: function or NOT_OPCODE
 */
int is_opcode(stack_t **stack, monty_data *data)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pop", monty_pop},
		{"add", monty_add},
		{"swap", monty_swap},
		{"pint", monty_pint},
		{"nop", monty_nop},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};

	while (instructions[i].opcode)
	{
		if (strcmp(data->args[0], instructions[i].opcode) == 0)
		{
			if (data->topback == 1)
				instructions[i].f(stack, data->line_num);
			else if (data->topback == -1)
				instructions[i].f(&(*stack)->next, data->line_num);
			return (OPCODE);
		}
		i++;
	}
	return (NOT_OPCODE);
}
