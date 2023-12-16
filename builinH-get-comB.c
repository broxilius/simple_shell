#include "shell.h"

/**
* get_builtin - Finds function associated with.
* @cmd:  built-in .
* Return: Pointer to the function, or NULL if .
*/
int (*get_builtin(char *cmd))(data_shell *)
{
	/* Array of structs built-in commands and their functions*/

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

	/* Loop the array matching built-in command */

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}
	/* Return function or NULL if not found*/
	return (builtin[i].f);
}
