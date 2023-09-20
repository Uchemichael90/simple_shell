#include "shell.h"

/**
 * repeat_char - counts the repetitions of a char
 *
 * @input: input string
 * @i: index
 * Return: repetitions
 */
int repeat_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeat_char(input - 1, i + 1));

	return (i);
}

/**
 * error_op - finds syntax errors
 *
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_op(char *input, int i, char last)
{
	int add;

	add = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			add = repeat_char(input, 0);
			if (add == 0 || add > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			add = repeat_char(input, 0);
			if (add == 0 || add > 1)
				return (i);
		}
	}

	return (error_op(input + 1, i + 1, *input));
}

/**
 * first_char - finds index of the first char
 *
 * @input: input string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */
int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_error - prints when a syntax error is found
 *
 * @datash: data structure
 * @input: input string
 * @i: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_error(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg1, *msg2, *error, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg1 = ": Syntax error: \"";
	msg2 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg1) + _strlen(msg2) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg1);
	_strcat(error, msg);
	_strcat(error, msg2);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_error - intermediate function to
 * find and print a syntax error
 *
 * @datash: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_error(data_shell *datash, char *input)
{
	int start = 0;
	int m_char = 0;
	int i = 0;

	m_char = first_char(input, &start);
	if (m_char == -1)
	{
		print_error(datash, input, start, 0);
		return (1);
	}

	i = error_op(input + start, 0, *(input + start));
	if (i != 0)
	{
		print_error(datash, input, start + i, 1);
		return (1);
	}

	return (0);
}
