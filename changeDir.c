/* cd.c */
#include "shell.h"

void change_back(data_shell *datash);
void change_to(data_shell *datash);
void change_previous(data_shell *datash);
void change_home(data_shell *datash);

/**
 * change_back - changes to the parent directory
 *
 * @datash: data relevant (environ)
 *
 * Return: no return
 */
void change_back(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("oldpwd", cp_pwd, datash);
	dir = datash->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("pwd", cp_pwd, datash);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	reverse_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			reverse_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("pwd", cp_strtok_pwd, datash);
	}
	else
	{
		chdir("/");
		set_env("pwd", "/", datash);
	}
	datash->status = 0;
	free(cp_pwd);
}

/**
 * change_to - changes to a directory given
 * by the user
 *
 * @datash: data relevant (directories)
 * Return: no return
 */
void change_to(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		catch_error(datash, 2);
		return;
	}

	cp_pwd = _strdup(pwd);
	set_env("oldpwd", cp_pwd, datash);

	cp_dir = _strdup(dir);
	set_env("pwd", cp_dir, datash);

	free(cp_pwd);
	free(cp_dir);

	datash->status = 0;

	chdir(dir);
}

/**
 * change_previous - changes to the previous directory
 *
 * @datash: data relevant (environ)
 * Return: no return
 */
void change_previous(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = _getenv("oldpwd", datash->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("oldpwd", cp_pwd, datash);

	if (chdir(cp_oldpwd) == -1)
		set_env("pwd", cp_pwd, datash);
	else
		set_env("pwd", cp_oldpwd, datash);

	p_pwd = _getenv("pwd", datash->_environ);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	datash->status = 0;

	chdir(p_pwd);
}

/**
 * change_home - changes to home directory
 *
 * @datash: data relevant (environ)
 * Return: no return
 */
void change_home(data_shell *datash)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenv("home", datash->_environ);

	if (home == NULL)
	{
		set_env("oldpwd", p_pwd, datash);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		catch_error(datash, 2);
		free(p_pwd);
		return;
	}

	set_env("oldpwd", p_pwd, datash);
	set_env("pwd", home, datash);
	free(p_pwd);
	datash->status = 0;
}
