#include "monty.h"
#include <string.h>
/**
 * tokenize_input - splits line into strings
 * @data: program data
 */
void tokenize_input(monty_data *data)
{
	char *token = NULL;
	int count = 0, bufsize = MAX_TOKENS;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		perror("Allocation Error");
		exit(EXIT_FAILURE);
	}
	token = _strdup(strtok(data->line, DELIM));
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		if (count >= bufsize)
		{
			bufsize += MAX_TOKENS;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Allocation Error");
				exit(EXIT_FAILURE);
			}
		}
		token = _strdup(strtok(NULL, DELIM));
	}
	tokens[count] = NULL;
	data->args = tokens;
}
