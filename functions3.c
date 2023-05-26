#include "monty.h"
/**
 * _pchar - rotates the stack to the bottom
 * @head: beginning of stack
 * @dt: integer in stack
*/
void _pchar(linked_l **head, unsigned int dt)
{
	int num;
	(void) head;
	(void) dt;

	if (gs.size == 0)
		myexit_error(-6, "pchar");
	num = gs.tail->n;
	if (num < 0 || num > 127)
		myexit_error(-10, NULL);
	printf("%c\n", num);
}
/**
 * _rotl - rotates the queue to the begining
 * @head: head of queue
 * @dt: pointer in queue
 */
void _rotl(linked_l **head, unsigned int dt)
{
	(void) head;
	if (gs.size == 0)
		myexit_error(0, NULL);

	dt = gs.tail->n;
	linked_ins_begin(dt);
	linked_remove(gs.tail);
}
/**
 * _chgmode - change mode: stack to que
 * @head: Unused
 * @dt: Unused
 */
void _chgmode(linked_l **head, unsigned int dt)
{
	(void) head;
	(void) dt;

	gs.mode *= -1;
}
/**
 * _pstr - rotates the stack to the bottom
 * @head: beginning of stack
 * @dt: integer in stack
 */
void _pstr(linked_l **head, unsigned int dt)
{
	linked_l *list;
	(void) head;
	(void) dt;

	list = gs.tail;
	for (; list; list = list->prev)
	{
		if (list->n == 0)
			break;
		printf("%c", list->n);
	}
	printf("\n");
}
/**
 * _rotr - rotates the stack to the bottom
 * @head: beginning of stack
 * @dt: integer in stack
*/
void _rotr(linked_l **head, unsigned int dt)
{
	(void) head;
	if (gs.size == 0)
		myexit_error(0, NULL);

	dt = gs.head->n;
	linked_ins_end(dt);
	linked_remove(gs.head);
}
