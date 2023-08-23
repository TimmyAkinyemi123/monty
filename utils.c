#include "monty.h"
/**
 * init_data - intializes monty program data
 * @data: monty program data
 */
void init_data(monty_data *data)
{
	data->line = NULL;
	data->line_num = 0;
	data->args = NULL;
}
