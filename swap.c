#include "monty.h"
/*
 * f_swap - Swaps the top two elements of the stack.
 * @head: stack
 * @number: Line Number
 * Return: No return
 **/
void f_pop(stack_t **head, unsigned int number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		safe_exit();
		/*free_stack(*head);*/
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head)->prev = (*head)->next;
	((*head)->next)->prev = NULL;
	(*head)->next = ((*head)->next)->next;
	((*head)->next)->prev = *head;
	((*head)->prev)->next = *head;
	free(temp);
}
