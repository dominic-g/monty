#include "monty.h"
/**
 * linked_start - starts the double linked stack
 */
void linked_start(void)
{
	gs.size = 0;
	gs.ln = 0;
	gs.head = NULL;
	gs.tail = NULL;
	gs.fd = NULL;
	gs.buffer = NULL;
	gs.intarg = 0;
	gs.mode = 1;
}
/**
 * linked_ins_begin - adds data at the beggining of the stack
 * @dt: interget to store the data
 * Return: 0 good 42 mem fail
 */

int linked_ins_begin(const int dt)
{
	linked_l *new_node, *node;

	new_node = malloc(sizeof(linked_l));
	if (new_node == NULL)
		return (42);
	new_node->n = dt;

	if (gs.size == 0)
	{
		gs.head = new_node;
		gs.head->prev = NULL;
		gs.head->next = NULL;
		gs.tail = new_node;
	}
	else
	{
		node = gs.head;
		new_node->next = node;
		new_node->prev = node->prev;
		gs.head = new_node;
		node->prev = new_node;
	}
	gs.size++;

	return (0);
}
/**
 * linked_ins_end - pushes dt to end of queue
 * @dt: integer to store the data
 * Return: 0 good 42 memory fail
 */
int linked_ins_end(const int dt)
{
	linked_l *new_node, *node;

	new_node = malloc(sizeof(linked_l));
	if (new_node == NULL)
		return (42);
	new_node->n = dt;

	if (gs.size == 0)
	{
		gs.head = new_node;
		gs.head->prev = NULL;
		gs.head->next = NULL;
		gs.tail = new_node;
	}
	else
	{
		node = gs.tail;
		new_node->next = node->next;
		new_node->prev = node;
		gs.tail = new_node;
		node->next = new_node;
	}
	gs.size++;

	return (0);
}
/**
 * linked_remove - removes node from queue
 * @node: queue position to be removed
 * Return: 0 on good or -1 on empty
 */
int linked_remove(linked_l *node)
{
	if (node == NULL || gs.size == 0)
		return (-1);
	if (node == gs.head)
	{
		gs.head = node->next;

		if (gs.head == NULL)
			gs.tail = NULL;
		else
			node->next->prev = NULL;
	}
	else
	{
		node->prev->next = node->next;

		if (node->next == NULL)
			gs.tail = node->prev;
		else
			node->next->prev = node->prev;
	}
	free(node);
	gs.size--;

	return (0);
}
/**
  * linked_destroy - exit the file reader and clear memory
  */
void linked_destroy(void)
{
	while (gs.size > 0) /* remove each element */
		linked_remove(gs.tail);
	if (gs.fd != NULL)
		fclose(gs.fd);
	if (gs.buffer != NULL)
		free(gs.buffer);
}
