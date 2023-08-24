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
