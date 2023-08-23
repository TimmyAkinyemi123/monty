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

	/* newnode points to the struct data and the value 'n'is stored in it */
	newnode->n = n;
	/* newnode points to the previous which is NULL since it is at the start */
	newnode->prev = NULL;
	/* newnode points to next and becomes the current head of list */
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
	/* create a new node and a temporary node */
	stack_t *endnode, *tempnode;

	/* allocate memory to the new node */
	endnode = malloc(sizeof(stack_t));

	/* if new node is empty return NULL */
	if (endnode == NULL)
	{
		return (NULL);
	}

	/* newnode points to the struct data and the value 'n'is stored in it */
	endnode->n = n;
	/* newnode points to the next which is NULL because it is at the end */
	endnode->next = NULL;

	/**
	 * if head is null, the list is empty and the new node becomes head
	 * and pointed to previous node becomes null also
	 */
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
