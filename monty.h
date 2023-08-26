#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
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
 * @topback: sets stack(top) or sets queue(back)
 */
typedef struct md
{
	char *line;
	char **args;
	char **list;
	unsigned int line_num;
	int topback;
} monty_data;

monty_data *data_ptr;

/* Primary Interpreter functions */
int monty_code(FILE *fd, monty_data *data);
void build_command_list(monty_data *data);
void tokenize_input(monty_data *data);
int is_opcode(stack_t **stack, monty_data *data);
void init_data(monty_data *data);
int stack_init(stack_t **stack);
void free_tokens(monty_data *data);

/* string functions */
char *_strdup(char *str);
int is_number(char *str);

/* doubly list functions */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* opcode functions */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/* is it a queue or stack */
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */
