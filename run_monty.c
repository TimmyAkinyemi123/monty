#include "monty.h"
/**
 * monty_code - code to run monty instructions
 * @fd: file descriptor
 * @data: monty program data
 * Return: On Success EXIT_SUCCESS or EXIT_FAILURE if fail
 */
int monty_code(FILE *fd, monty_data *data)
{
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, fd) != -1)
	{
		line_number++;
		data->line_num = line_number;

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		if (line[0] == '\0')
			continue;
<<<<<<< HEAD
		data->line = line;
		tokenize_input(data_ptr);
=======
		data->line = _strdup(line);
		tokenize_input(data);
>>>>>>> a7573008b39e961c729ae09da345ca282564e4d1

		if (is_opcode(&stack, data) == NOT_OPCODE)
		{
<<<<<<< HEAD
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, data->args[0]);
			exit_status = EXIT_FAILURE;
			free_tokens();
			free(line);
			free_dlistint(stack);
			break;
=======
			if (is_opcode(&stack, data) == NOT_OPCODE)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n",
						line_number, data->args[0]);
				exit_status = EXIT_FAILURE;
				free_tokens(data);
				free(data->line);
				break;
			}
>>>>>>> a7573008b39e961c729ae09da345ca282564e4d1
		}
		free_tokens(data);
	}
	free(line);
	free_dlistint(stack);
	return (exit_status);
}
