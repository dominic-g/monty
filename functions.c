#include "monty.h"

/**
  * _pall -  prints stck values from the begining
  * @head: void
  * @dt: void
  */
void _pall(linked_l **head, unsigned int dt)
{
	linked_l *list;
	(void)head;
	(void)dt;

	list = gs.tail;
	if (gs.size == 0)
		return;
	for (; list; list = list->prev)
		printf("%d\n", list->n);
}
/**
* _swap - interchanges twovalues of the stack
* @head: void
* @dt: store integer from node
*/
void _swap(linked_l **head, unsigned int dt)
{
	(void)head;
	if (gs.size <= 2)
		myexit_error(-8, "swap");

	dt = gs.tail->n;
	gs.tail->n = gs.tail->prev->n;
	gs.tail->prev->n = dt;
}
/**
* _pint- output the value on the begining
* @head: void
* @dt: void
*/
void _pint(linked_l **head, unsigned int dt)
{
	(void)head;
	(void)dt;

	if (gs.size == 0)
		myexit_error(-6, "pint");

	printf("%d\n", gs.tail->n);
}
/**
  * _push - pushes element to queue
  * @head: void
  * @dt: check status
  */

void _push(linked_l **head, unsigned int dt)
{
	(void)head;

	if (gs.mode == 1)/* Stack */
		dt = linked_ins_end(gs.intarg);
	else /* Queue */
		dt = linked_ins_begin(gs.intarg);
	if (dt == 42)
		myexit_error(-5, NULL);
}
/**
  * _pop - pops out element from queue
  * @head: void
  * @dt: void
  */
void _pop(linked_l **head, unsigned int dt)
{
	(void)head;
	(void)dt;

	if (gs.size == 0)
		myexit_error(-7, NULL);
	linked_remove(gs.tail);
}
