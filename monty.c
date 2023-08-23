#include "monty.h"
/**
 * main - run monty code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	int exit_status = EXIT_SUCCESS;
	monty_data data = {NULL};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	init_data(&data);
	exit_status = monty_code(fd, &data);
	fclose(fd);

	return (exit_status);
}
