#include "monty.h"
/*
 * f_pop - Remove the top elemnt of the stack.
 * @head: stack
 * @number: Line Number
 * Return: No return
 **/
void f_pop(stack_t **head, unsigned int number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", number);
		safe_exit();
		/*free_stack(*head);*/
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
