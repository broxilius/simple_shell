#include "shell.h"

/**
 * exec_line - Executes a command line.
 * @datash: The data structure containing shell information.
 * Return: exit status of the executed command or 1 if no command is provided.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
