#include "shell.h"

/**
 * auth_helping - Help information for the builtin help.
 * Return: no return
 */
void auth_helping(void)
{
	char *helping = "helping: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "\tDisplay information on builtin commands.\n ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Displays some summaries of builtin commands.\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}
/**
 * auth_helping_aliass - Help information for the builtin alias.
 * Return: no return
 */
void auth_helping_aliass(void)
{
	char *helped = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, helped, _strlen(helped));
	helped = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, helped, _strlen(helped));
}
/**
 * auth_helping_container - Help information for the builtin alias.
 * Return: no return
 */
void auth_helping_container(void)
{
	char *helpers = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, helpers, _strlen(helpers));
	helpers = "\tSwitch the shell working directory.\n ";
	write(STDOUT_FILENO, helpers, _strlen(helpers));
}
