#include "monty.h"
/**
* execute_op - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: int
*/
int execute_op(char *content, stack_t **stack, unsigned int line_counter, FILE *file)
{
	instruction_t op_st[] = {
		{"push", f_push}, 
		{NULL, NULL}
	};
	int i = 0;
	char *op_func;

	/* 1) Get Argument function and atgument value. */
	op_func = strtok(content, " \n\t");
	global.arg = strtok(NULL, " \n\t");

	/* 2) Find the match function and execute that. */
	while (op_st[i].opcode && op_func)
	{
		if (strcmp(op_func, op_st[i].opcode) == 0)
		{
			op_st[i].f(stack, line_counter);
			return (0);
		}
		i++;
	}
	
	/* 3) If not found function print error and close file and free stack. */
	if (op_func && op_st[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, op_func);
		fclose(file);
		free(content);
		exit(EXIT_FAILURE);
	}

	return (1);
}
