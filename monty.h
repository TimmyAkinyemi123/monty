#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty_macros.h"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct md - monty data
 * @args: tokenized strings
 * @line: instruction entered by user
 * @line_num: line number
 */
typedef struct md
{
	char *line;
	char **args;
	unsigned int line_num;
} monty_data;

/* Primary Interpreter functions */
int monty_code(FILE *fd, monty_data *data);
void tokenize_input(monty_data *data);
int is_opcode(monty_data *data);
void init_data(monty_data *data);

/* string functions */
char *_strdup(char *str);
#endif /* MONTY_H */
