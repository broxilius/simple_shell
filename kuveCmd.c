#include "shell.h"

/**
 * read_line - Reads a line from standard input.
 * @i_eof: Pointer to an integer to indicate end-of-file status.
 * Return: A pointer to the read line.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
