#include "shell.h"

/**
* read_line - Reads .
*@i_eof: Pointe e updated with the getline return value.
* Return: A point string.
*/
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	/* Read a line from the using getline */
	*i_eof = getline(&input, &bufsize, stdin);

	/* Return the pointer tring */
	return (input);
}
