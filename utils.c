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
}

/**
 * stack_init - initialize the stack pointer
 * @stack: pointer to pointer
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
 * @data: monty program data
 * Return: function or NOT_OPCODE
 */
int is_opcode(monty_data *data)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push" monty_push},
		{NULL, NULL}};

	while (instructions[i].opcode)
	{
		if (strcmp(data->args[0], instructions[i].opcode))
			return(instructions[i].f(&stack, data->line_num));
		i++;
	}
	return (NOT_OPCODE);
}
