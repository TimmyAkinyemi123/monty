#include "monty.h"

/**
 * add_dnodeint - a function that adds a new node at the beginning
 * of a doubly linked list
 * @head: a double pointer head of doublylinked list(beginning point)
 * @n: data that the list should contain
 * Return: address of newnode
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newnode; /*create the new node variable */

	newnode = malloc(sizeof(stack_t)); /* allocates memory to the new node */

	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = newnode;
	}

	*head = newnode;
	return (newnode);
}

/**
 * add_dnodeint_end - a function that adds a new node at the end
 * of a doubly linked list
 * @head: a double pointer head of doublylinked list(beginning point)
 * @n: data that the list should contain
 * Return: address of newnode
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *endnode, *tempnode;

	endnode = malloc(sizeof(stack_t));

	/* if new node is empty return NULL */
	if (endnode == NULL)
		return (NULL);

	endnode->n = n;
	endnode->next = NULL;

	if (*head == NULL)
	{
		endnode->prev = NULL;
		*head = endnode;
	}
	else
	{
		tempnode = *head;
		while (tempnode->next != NULL)
		{
			tempnode = tempnode->next;
		}
		tempnode->next = endnode;
		endnode->prev = tempnode;
	}

	return (endnode);
}

/**
 * free_dlistint - a function that frees a doubly
 * linked list
 * @head: head of doublylinked list(beginning point)
 * Return: no value
 */
void free_dlistint(stack_t *head)
{
	/* tempnode keeps track of nodes being freed up */
	stack_t *tempnode;

	while (head != NULL)
	{
		/* start from the beginning */
		tempnode = head;
		/* head moves to the next node */
		head = head->next;
		/* node is freed and moves to the beginning again */
		free(tempnode);
	}
}
