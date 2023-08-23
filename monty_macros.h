#ifndef MONTY_MACROS_H
#define MONTY_MACROS_H

#define NOT_OPCODE -99
#define MAX_TOKENS 1024
#define DELIM " \n"

/**
 * @temp: starting point in a doubly linked list
 * @fileptr: points to file
 *
 *
 */
typedef struct global_variable
{
	stack_t *temp;
	FILE *fileptr;
	char *argmt;
	char *buff;
} my_globalvar;

#endif
