#include "monty.h"

/**
 * unknown_error - print out monty code error
 * message
 * @line_number: line number
 * @instruction: command entered
 */
void unknown_error(unsigned int line_number, char *instruction)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
}
