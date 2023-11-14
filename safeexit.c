#include "monty.h"
/**
 * safe_exit - free global
 * Return: No return
 *
 */
void safe_exit(void)
{
	fclose(global.file);
	free(global.content);
}
