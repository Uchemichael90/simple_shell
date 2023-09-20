#include "shell.h"

/**
 * check_folder - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_folder(r_var **h, char *in, data_shell *data)
{
	int row, chart, j, lval;
	char **_folder;

	_folder = data->_environ;
	for (row = 0; _folder[row]; row++)
	{
		for (j = 1, chart = 0; _folder[row][chart]; chart++)
		{
			if (_folder[row][chart] == '=')
			{
				lval = _strlen(_folder[row] + chart + 1);
				add_end(h, j, _folder[row] + chart + 1, lval);
				return;
			}

			if (in[j] == _folder[row][chart])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_end(h, j, NULL, 0);
}

/**
 * checked_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int checked_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int i, lst, pwd;

	lst = _strlen(st);
	pwd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_end(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_end(h, 2, data->pid, pwd), i++;
			else if (in[i + 1] == '\n')
				add_end(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_end(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_end(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_end(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_end(h, 0, NULL, 0);
			else
				check_folder(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replace_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replace_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *index;
	int i, j, k;

	index = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(index->len_var) && !(index->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (index->len_var && !(index->len_val))
			{
				for (k = 0; k < index->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < index->len_val; k++)
				{
					new_input[i] = index->val[k];
					i++;
				}
				j += (index->len_var);
				i--;
			}
			index = index->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_var - calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *index;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	olen = checked_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	index = head;
	nlen = 0;

	while (index != NULL)
	{
		nlen += (index->len_val - index->len_var);
		index = index->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replace_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rival(&head);

	return (new_input);
}
