#include "monty.h"
/**
 * f_push - Add new element to the stack
 * @head: stack head
 * @l_number: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int l_number)
{
	int n, j = 0, is_valid = 0;

	/* 1) Check if the argument is valid. */
	if (global.arg)
	{
		if (global.arg[0] == '-')
			j++;
		for (; global.arg[j] != '\0'; j++)
			if (global.arg[j] > 57 || global.arg[j] < 48)
				flag = 1;
		if (is_valid == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", l_number);
			fclose(global.file);
			free(global.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_number);
		fclose(global.file);
		free(global.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* 2) Adding new node. */
	n = atoi(global.arg);
	addnode(head, n);
}
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{
	/* 1) Check if head is Null*/

	/* 2) Add Element to stack */
	stack_t *temp, *new_node;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
