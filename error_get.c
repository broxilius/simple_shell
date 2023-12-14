#include "shell.h"

/**
 * get_error - Retrieves an error message based on the shell data and
 * @datash: Shell data structure containing relevant information.
 * @eval: Evaluation result or error code.
 * return : void
**/
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = error_env(datash);
			break;
		case 126:
			error = error_path_126(datash);
			break;
		case 127:
			error = error_not_found(datash);
			break;
		case 2:
			if (_strcmp("exit", datash->args[0]) == 0)
				error = error_exit_shell(datash);
			else if (_strcmp("cd", datash->args[0]) == 0)
				error = error_get_cd(datash);
			break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
