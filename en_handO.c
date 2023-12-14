#include "shell.h"

/**
 * cmp_env_name - Compares an environment variable name with a given name.
 * @nenv: The environment variable name to compare.
 * @name: The name to compare with the environment variable name.
 * Return: [Description of the return value, if any. For example, comparison result.]
**/
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * @_environ: Pointer to the array of environment variables.
 * Return: A pointer to the value of the specified environment variable, or NULL if not found.
**/
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Init ptr_env val */
	ptr_env = NULL;
	mov = 0;
	/* */
	/*  */
	for (i = 0; _environ[i]; i++)
	{
		/* comments here */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}
/**
 * _env - [Description of the function's purpose]
 * @datash: [Description of the datash parameter]
 * Return: [Description of the return value, if any]
**/
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
