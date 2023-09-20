#include "shell.h"

/**
 * copy_in - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_in(char *name, char *value)
{
	char *new;
	int length_name, lenght_value, lenght;

	length_name = _strlen(name);
	lenght_value = _strlen(value);
	lenght = length_name + lenght_value + 2;
	new = malloc(sizeof(char) * (lenght));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_in(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _realcdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = copy_in(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		catch_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int x, j, k;

	if (datash->args[1] == NULL)
	{
		catch_error(datash, -1);
		return (1);
	}
	k = -1;
	for (x = 0; datash->_environ[x]; x++)
	{
		var_env = _strdup(datash->_environ[x]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			k = x;
		}
		free(var_env);
	}
	if (k == -1)
	{
		catch_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (x));
	for (x = j = 0; datash->_environ[x]; x++)
	{
		if (x != k)
		{
			realloc_environ[j] = datash->_environ[x];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[k]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
