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
	if (!str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * _strtrim - removes beginning whitespace
 * characters
 * @str: string to modify
 */
void _strtrim(char *str)
{
	int start = 0, i = 0;
	int end = strlen(str) - 1;

	/* find start and end index of nonspace character */
	while (str[start] == ' ')
		start++;
	while (end > start && str[end] == ' ')
		end--;
	/*shifting characters to the left */
	for (i = 0; i <= end - start; i++)
		str[i] = str[start + i];
	str[i] = '\0';
}

