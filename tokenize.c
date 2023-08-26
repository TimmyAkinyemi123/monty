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
		fprintf(stderr, "Error: malloc failed\n");
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
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
		}
		token = _strdup(strtok(NULL, DELIM));
	}
	tokens[count] = NULL;
	data->args = tokens;
}
/**
 * build_command_list - Builds the command list for a
 * single command line
 * @data: Program data
 * Return: void
 */
void build_command_list(monty_data *data)
{
	char **commands;
	char *command;
	int i = 0;

	commands = malloc(MAX_TOKENS * sizeof(char *));
	if (!commands)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((command = _strdup(strtok(i ? NULL : data->line, ";"))))
		commands[i++] = command;
	commands[i] = NULL;
	data->list = commands;
}
