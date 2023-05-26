#ifndef MAIN_H
#define MAIN_H

#include <ctype.h> /*checking digit*/
#include <stdio.h>
#include <string.h> /*for string tok*/
#include <stdlib.h>
#include <unistd.h> /*at the ends*/

/**
 * struct linked_d - queue of doule linked linked rep
 * @n: number int
 * @prev: the element before in the queue
 * @next: the element after in the queue
 *
 * Description: structure for linked list
 */
typedef struct linked_d
{
	int n;
	struct linked_d *prev;
	struct linked_d *next;
} linked_l;
/**
 * struct opcoode_c - the commands list
 * @opcode: the opcode
 * @f: callback function to execute the code 
 *
 * Description: handling the command
 */
typedef struct opcoode_c
{
	char *opcode;
	void (*f)(linked_l **stack, unsigned int line_number);
} opcoode_l;
/**
 * struct data_holder - the container for the data
 * @size: the struct size
 * @head: first item in list pointer
 * @tail: last item in list pointer
 * @fd: file
 * @buffer: buffer
 * @intarg: agument number
 * @mode: mode used
 */
typedef struct data_holder
{
	size_t size;
	unsigned int ln;
	linked_l *head;
	linked_l *tail;
	FILE *fd;
	void *buffer;
	int intarg;
	int mode;
} data_hold;

extern data_hold gs;

/* functions.c */
void _push(linked_l **stack, unsigned int dt);
void _pint(linked_l **stack, unsigned int dt);
void _pall(linked_l **stack, unsigned int dt);
void _pop(linked_l **stack, unsigned int dt);
void _swap(linked_l **stack, unsigned int dt);

/* functions2.c */
void _add(linked_l **head, unsigned int dt);
void _sub(linked_l **head, unsigned int dt);
void _div(linked_l **head, unsigned int dt);
void _mod(linked_l **head, unsigned int dt);
void _mul(linked_l **head, unsigned int dt);

/* functions3.c */
void _rotl(linked_l **head, unsigned int dt);
void _rotr(linked_l **head, unsigned int dt);
void _pchar(linked_l **head, unsigned int dt);
void _pstr(linked_l **head, unsigned int dt);
void _chgmode(linked_l **head, unsigned int dt);

/* functions4.c */
void linked_start(void);
void linked_destroy(void);
int linked_ins_end(const int dt);
int linked_ins_begin(const int dt);
int linked_remove(linked_l *node);

/* functions5.c */
int run_opcode(char *buf);
void myexit_error(int code, char *string);
int chk_int(const char *argint);
void nop(linked_l **stack, unsigned int data);
#endif /* MAIN_H */
