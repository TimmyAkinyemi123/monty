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

		if (line[strlen(line) -1] == '\n')
			line[strlen(line) -1] = '\0';
		if (line == NULL)
			continue;
		data->line = line;
		tokenize_input(data);

		if (data->args[0])
		{
			if (is_opcode(&stack, data) == NOT_OPCODE)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n",
						line_number, data->args[0]);
				exit_status = EXIT_FAILURE;
				free_tokens();
				free(line);
				break;
			}
			free_tokens();
		}
	}
	free(line);
	return (exit_status);
}
