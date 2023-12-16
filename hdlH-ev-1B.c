#include "shell.h"

/**
* cmp_env_name - Compare environment variable.
* @nenv: Environment string.
* @name: Name compare.
* Return: Number of characters prefix, or 0 if not a match.
*/

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
* _getenv -Get value of variable.
* @name: Name of variable.
* @_environ:Array variables.
* Return: Value the variable, or NULL if not found.
*/

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize value to NULL */

	ptr_env = NULL;
	mov = 0;

	/* Iterate environment variables */

	for (i = 0; _environ[i]; i++)
	{
		/* Compare the name of variable */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			/* If a match is found, set ptr_env variable */

			ptr_env = _environ[i];
			break;
		}
	}

	/* Return the value variable (skipping the name) */
	return (ptr_env + mov);
}

/**
*_env - Print the variables.
* @datash: Shell structure.
* Return: Always 1.
*/

int _env(data_shell *datash)
{
	int i, j;
	/* Iterate through the variables */
	for (i = 0; datash->_environ[i]; i++)
	{

		/* Calculate of the environment variable */
		for (j = 0; datash->_environ[i][j]; j++)
			;
		/* Write variable to standard output */
		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
