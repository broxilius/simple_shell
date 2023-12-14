#include "shell.h"

/**
 * get_builtin - Retrieves a pointer to a built-in function based on the command name.
 * @cmd: The command name for which to retrieve the built-in function.
 * Return: A pointer to the corresponding built-in function, or NULL if not found.
**/
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}
	return (builtin[i].f);
}
