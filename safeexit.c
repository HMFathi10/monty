#include "monty.h"
/*
 * safe_exit - free global
 * Return: No return
 *
 **/
void safe_exit()
{
	fclose(global.file);
	free(global.content);
}
