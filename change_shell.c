#include "shell.h"

/**
 * change_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int change_shell(data_shell *datash)
{
	char *dir;
	int home, ishome, dash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		home = _strcmp("$HOME", dir);
		ishome = _strcmp("~", dir);
		dash = _strcmp("--", dir);
	}

	if (dir == NULL || !home || !ishome || !dash)
	{
		change_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		change_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		change_back(datash);
		return (1);
	}

	change_to(datash);

	return (1);
}
