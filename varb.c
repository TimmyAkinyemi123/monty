#include "monty.h"

/* free and set global variables */

/**
 * free_varb - free memory in global variables
 *
 * Return: no value
 */
void free_varb()
{
}

/**
 * init_varb - initialize global variables
 * @fd: file descriptor
 * Return: no value
 */
void init_varb(FILE *fd)
{
	varb.argmt = NULL;
	varb.topback = 1;
}
