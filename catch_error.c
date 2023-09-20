#include "shell.h"

/**
 * catch_error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int catch_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_bro(datash);
		break;
	case 126:
		error = error_way_755(datash);
		break;
	case 127:
		error = error_null_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_ext_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_cd(datash);
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
