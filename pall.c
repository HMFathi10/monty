#include "monty.h"
/**
 * f_pall - Prints all the values on the stack
 * @head: stack
 * @number: Line number
 * Return: No return
 */
void f_pall(stack_t **head, unsigned int number)
{
	stack_t *temp;
	(void)number;

	temp = *head;
	/* 1) Check if the stack is empty. */
	if (temp == NULL)
		return;

	/* 2) Print all values. */
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
