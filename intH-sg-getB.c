#include "shell.h"

/**
* get_sigint - a signal SIGINT signal
* @sig:  int signal
*/

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
