#include "monty.h"
/**
 * f_pint - Prints the value at the top of the stack.
 * @head: stack
 * @number: Line Number
 * Return: No return
 */
void f_pint(stack_t **head, unsigned int number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		safe_exit();
		/*free_stack(*head);*/
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
