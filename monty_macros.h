#ifndef MONTY_MACROS_H
#define MONTY_MACROS_H

#define NOT_OPCODE -99
#define MAX_TOKENS 1024
#define DELIM " \n"

/**
 * struct global_variable - alias for variables
 * @temp: starting point in a doubly linked list
 * @fileptr: points to file
 * @argv1: second index of the argument in a line
 *
 */
typedef struct global_variable
{
	stack_t *temp;
	FILE *fileptr;
	char *argv1;
	char *buff;
} my_globalvar;

#endif
