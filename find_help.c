#include "shell.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_shell *datash)
{

	if (datash->args[1] == 0)
		aux_helping_general();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		aux_helping_setfolder();
	else if (_strcmp(datash->args[1], "env") == 0)
		aux_helping_folder();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		aux_helping_unsetfolder();
	else if (_strcmp(datash->args[1], "help") == 0)
		auth_helping();
	else if (_strcmp(datash->args[1], "exit") == 0)
		aux_helping_exit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		auth_helping_container();
	else if (_strcmp(datash->args[1], "alias") == 0)
		auth_helping_aliass();
	else
		write(STDERR_FILENO, datash->args[0],
		      _strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
