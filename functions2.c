#include "monty.h"
/**
  * _div - divides the top two elements of the stack
  * @head: void
  * @dt: store integer from node
  */
void _div(linked_l **head, unsigned int dt)
{
	(void)head;

	if (gs.size < 2)
		myexit_error(-8, "div");

	dt = gs.tail->n;
	if (dt == 0)
		myexit_error(-9, NULL);
	linked_remove(gs.tail);
	dt /= gs.tail->n;
	gs.tail->n = dt;
}
/**
  * _sub - subtract element of queue
  * @head: void
  * @dt: int from queue storage
  */
void _sub(linked_l **head, unsigned int dt)
{
	(void)head;

	if (gs.size < 2)
		myexit_error(-8, "sub");

	dt = gs.tail->prev->n;
	dt -= gs.tail->n;
	gs.tail->prev->n = dt;
	linked_remove(gs.tail);
}
/**
  * _add - adds elements of queue
  * @head: void
  * @dt: void
  */
void _add(linked_l **head, unsigned int dt)
{
	(void)head;

	if (gs.size < 2)
		myexit_error(-8, "add");

	dt = gs.tail->n;
	linked_remove(gs.tail);
	dt += gs.tail->n;
	gs.tail->n = dt;
}
/**
  * _mul - multiply the top two elements of the stack
  * @head: void
  * @dt: store interger from node
  */
void _mul(linked_l **head, unsigned int dt)
{
	(void)head;

	if (gs.size < 2)
		myexit_error(-8, "mul");

	dt = gs.tail->n;
	linked_remove(gs.tail);
	dt *= gs.tail->n;
	gs.tail->n = dt;
}
/**
  * _mod - modulo the top two elements of the stack
  * @head: void
  * @dt: store integer from node
  */
void _mod(linked_l **head, unsigned int dt)
{
	(void)head;

	if (gs.size < 2)
		myexit_error(-8, "mod");

	dt = gs.tail->n;
	if (dt == 0)
		myexit_error(-9, NULL);
	linked_remove(gs.tail);
	dt %= gs.tail->n;
	gs.tail->n = dt;
}
