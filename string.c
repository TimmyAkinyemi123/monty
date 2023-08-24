#include "monty.h"

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 * Return: A pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup;
	size_t len;

	if (str == NULL)
		return (NULL);
	len = strlen(str) + 1;

	dup = malloc(len);
	if (!dup)
		return (NULL);
	strcpy(dup, str);
	return (dup);
}

/**
 * is_number - checks if a string is a number
 * @str: string to check
 * Return: 1 if it's a number, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
