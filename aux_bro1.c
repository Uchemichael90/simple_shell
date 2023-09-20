#include "shell.h"

/**
 * error_bro - error message for bro in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: fail message.
 */
char *error_bro(data_shell *datash)
{
	int size;
	char *fail;
	char *ver_str;
	char *message;

	ver_str = aux_itoa(datash->counter);
	message = ": Unable to add/remove from environment\n";
	size = _strlen(datash->av[0]) + _strlen(ver_str);
	size += _strlen(datash->args[0]) + _strlen(message) + 4;
	fail = malloc(sizeof(char) * (size + 1));
	if (fail == 0)
	{
		free(fail);
		free(ver_str);
		return (NULL);
	}

	_strcpy(fail, datash->av[0]);
	_strcat(fail, ": ");
	_strcat(fail, ver_str);
	_strcat(fail, ": ");
	_strcat(fail, datash->args[0]);
	_strcat(fail, message);
	_strcat(fail, "\0");
	free(ver_str);

	return (fail);
}
/**
 * error_way_755 - error message for way and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The fail string.
 */
char *error_way_755(data_shell *datash)
{
	int size;
	char *ver_str;
	char *fail;

	ver_str = aux_itoa(datash->counter);
	size = _strlen(datash->av[0]) + _strlen(ver_str);
	size += _strlen(datash->args[0]) + 24;
	fail = malloc(sizeof(char) * (size + 1));
	if (fail == 0)
	{
		free(fail);
		free(ver_str);
		return (NULL);
	}
	_strcpy(fail, datash->av[0]);
	_strcat(fail, ": ");
	_strcat(fail, ver_str);
	_strcat(fail, ": ");
	_strcat(fail, datash->args[0]);
	_strcat(fail, ": Permission denied\n");
	_strcat(fail, "\0");
	free(ver_str);
	return (fail);
}
