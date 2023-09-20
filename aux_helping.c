#include "shell.h"

/**
 * aux_helping_folder - Help information for the builtin env
 * Return: no return
 */
void aux_helping_folder(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the enviroment shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));

}
/**
 * aux_helping_setfolder - Help information for the builtin setenv
 * Return: no return
 */
void aux_helping_setfolder(void)
{

	char *helping = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "int replace)\n\t";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}
/**
 * aux_helping_unsetfolder - Help information for the builtin unsetenv
 * Return: no return
 */
void aux_helping_unsetfolder(void)
{
	char *helping = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}


/**
 * aux_helping_general - Entry point for help information for the help builtin
 * Return: no return
 */
void aux_helping_general(void)
{
	char *helping = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Type 'helping' to see the list";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "Type 'helping name' to find out about the function 'name'.\n\n ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, helping, _strlen(helping));
	helping = "unsetenv [variable]\n";
	write(STDOUT_FILENO, helping, _strlen(helping));
}
/**
 * aux_helping_exit - Help information fot the builint exit
 * Return: no return
 */
void aux_helping_exit(void)
{
	char *exit = "Cancel: exit [n]\n Cancel shell.\n";

	write(STDOUT_FILENO, exit, _strlen(exit));
	exit = "cancel the shell with a status of N. If N is ommited, then exit";
	write(STDOUT_FILENO, exit, _strlen(exit));
	exit = "status is  the last command executed\n";
	write(STDOUT_FILENO, exit, _strlen(exit));
}
