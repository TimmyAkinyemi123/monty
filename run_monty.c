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
	int i = 0, last = 0;

	while (getline(&line, &len, fd) != -1)
	{
		line_number++;
		data->line_num = line_number;

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		_strtrim(line);
		if (line[0] == '\0' || check_comment(line))
			continue;
		data->line = _strdup(line);
		build_command_list(data);

		for (i = 0; data->list[i]; ++i)
		{
			data->line = data->list[i];
			tokenize_input(data);
			if (is_opcode(&stack, data) == NOT_OPCODE)
			{
				unknown_error(line_number, data->args[0]);
				exit_status = EXIT_FAILURE;
				free_tokens(data);
				free(data->line);
				break;
			}
			last = 1;
		}
		free_tokens(data);
	}
	free(line);
	free_dlistint(stack);
	if (last)
		printf("0\n");
	return (exit_status);
}

/**
 * check_comment - check if first non-space character
 * is #
 * @line: line to check
 * Return: 1 if line is #
 */
int check_comment(char *line)
{
	while (*line == ' ')
		line++;

	return (*line == '#');
}

