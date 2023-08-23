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
