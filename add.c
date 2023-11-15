#include "monty.h"
/**
 * f_add - Add the top two elements of the stack.
 * @head: stack
 * @number: Line Number
 * Return: No return
 */
void f_add(stack_t **head, unsigned int number)
{
	stack_t *temp;
	int counter = 0;

	temp = *head;
	while (temp && counter != 2)
	{
		temp = temp->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		safe_exit();
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	temp->next->n = temp->n + temp->next->n;
	temp->next->prev = NULL;
	*head = (*head)->next;
	free(temp);
}
