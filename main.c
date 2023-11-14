#include "monty.h"
global_t global = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	int read_line = 1;
	size_t size = 0;
	char *line_content;
	int line_counter = 0;
	stack_t *main_stack = NULL;

	/* 1) Check if the user does not give any file or more than one argument. */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* 2) Open file and if it's not possible to open the file, print error. */
	file = fopen(argv[1], "r");
	global.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* 3) Reads the file lines and execute the right function. */
	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &size, file);
		global.content = line_content;
		line_counter++;
		if (read_line > 0)
		{
			execute_op(line_content, &main_stack, line_counter, file);
		}
		free(line_content);
	}

	/* 4) Free the stack and close the file. */
	/*free_stack(stack);*/
	fclose(file);
	return (0);
}
