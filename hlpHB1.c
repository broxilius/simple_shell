#include "shell.h"

/**
* aux_help - Displays about the 'help' command
* Return: void
*/
void aux_help(void)
{
	/* Help 'help' command */
	char *help = "help: help [-dms] [pattern ...]\n";

	/* Write the help message to the standard output*/
	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
* aux_help_alias - Displays about the 'alias' command
* Return: void
*/
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
* aux_help_cd - Displays about the 'cd' command
* Return: void
*/
void aux_help_cd(void)
{
	/* Help for 'cd' command */
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
