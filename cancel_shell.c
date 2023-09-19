#include "shell.h"

/**
 * cancel_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int cancel_shell(data_shell *datash)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int large_number;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		large_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || large_number)
		{
			catch_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}
