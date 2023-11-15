#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @number: line_number
* @file: poiner to monty file
* @content: line content
* Return: int
*/
int execute(char *content, stack_t **stack, unsigned int number, FILE *file)
{
	instruction_t op_st[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
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
			op_st[i].f(stack, number);
			return (0);
		}
		i++;
	}

	/* 3) If not found function print error and close file and free stack. */
	if (op_func && op_st[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", number, op_func);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
