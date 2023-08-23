#ifndef MONTY_MACROS_H
#define MONTY_MACROS_H

#define NOT_OPCODE -99
#define MAX_TOKENS 1024
#define DELIM " \n"

/**
 * struct global_variable - alias for variables
 * @argmt: second index of the argument in a line
 * @topback: set stack(top) or queue(back)
 */
typedef struct global_variable
{
	char *argmt;
	int topback;
} my_globalvar;

extern my_globalvar varb; /* a defined global variable */

#endif
