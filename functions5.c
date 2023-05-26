#include "monty.h"
/**
 * run_opcode - execute commands
 * @buf: the line fom file
 * Return: 0 if nothing
 */
int run_opcode(char *buf)
{
	opcoode_l cmd[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", nop}, {"sub", _sub},
		{"mul", _mul}, {"div", _div}, {"mod", _mod}, {"rotl", _rotl},
		{"rotr", _rotr}, {"pchar", _pchar}, {"pstr", _pstr}, {"queue", _chgmode},
		{"stack", _chgmode}, {NULL, NULL}
	};
	char *opcode, *argint, *delim = " \t\n\r";
	unsigned int i;
	int intarg = 0;

	opcode = strtok(buf, delim);
	if (opcode == NULL || opcode[0] == '#')/*if empty line or comment*/
		return (0);
	for (i = 0; cmd[i].f != NULL; i++)
	{
		if (strcmp(opcode, cmd[i].opcode) == 0)
		{
			if (i == 0)
			{
				argint = strtok(NULL, delim);
				intarg = chk_int(argint);/*chk int arg*/
				if (intarg == -4)/*push arg is not int*/
					myexit_error(-4, NULL);
			}
			cmd[i].f(NULL, 0);/*call respective funciton*/
			break;
		}
	}
	if (cmd[i].f == NULL)/*IF NO MATCH*/
		myexit_error(-3, opcode);

	return (0);
}
/**
  * myexit_error - output error message
  * @code: error code to check for message
  * @string: where it occured
  **/
void myexit_error(int code, char *string)
{
	code *= -1;
	switch (code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n", string);
			break;
		case 3:
			printf("L%d: unknown instruction %s\n", gs.ln, string);
			break;
		case 4:
			printf("L%d: usage: push integer\n", gs.ln);
			break;
		case 5:
			printf("Error: malloc failed\n");
			break;
		case 6:
			printf("L%d: can't %s, stack empty\n", gs.ln, string);
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n", gs.ln);
			break;
		case 8:
			printf("L%d: can't %s, stack too short\n", gs.ln, string);
			break;
		case 9:
			printf("L%d: division by zero\n", gs.ln);
			break;
		case 10:
			printf("L%d: can't pchar, value out of range\n", gs.ln);
			break;
	}
	linked_destroy();
	exit(EXIT_FAILURE);
}
/**
 * chk_int - chack sg for inpur out
 * @argint: arg to be checked
 * Return: 0 or -4
 */
int chk_int(const char *argint)
{
	int i, check;

	if (argint == NULL)
		return (-4);/*second strtok fails*/

	for (i = 0; argint[i]; i++)
	{
		if (argint[i] == '-' && argint[i + 1] != '-')
			continue;
		check = isdigit(argint[i]);
		if (check == 0)
			return (-4);
	}
	gs.intarg = atoi(argint);
	return (0);
}
/**
* nop - empty function
* @head: void
* @data: void
*/
void nop(linked_l **head, unsigned int data)
{
	(void)head;
	(void)data;
}
