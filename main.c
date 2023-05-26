#define _POSIX_C_SOURCE 200809L
#include "monty.h"

data_hold gs;

/**
  * main - monty bytecode interpreter
  * @ac: argument count
  * @av: argument variables entered from the command line
  * Return: 0 on success
  */

int main(int ac, char **av)
{
	FILE *FD;
	char *buffer = NULL;
	ssize_t glcount = 0;
	size_t bufflen = 0;

	linked_start();
	if (ac != 2)
		myexit_error(-1, NULL);
	FD = fopen(av[1], "r");
	if (FD == NULL)
		myexit_error(-2, av[1]);
	gs.fd = FD;
	while (glcount != -1)
	{
		gs.ln++;
		glcount = getline(&buffer, &bufflen, FD);
		if (glcount == -1)
			break;
		gs.buffer = buffer;
		run_opcode(buffer);
	}
	linked_destroy();
	return (EXIT_SUCCESS);
}
