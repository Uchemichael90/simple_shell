#include "shell.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *old, *template;

	old = malloc(sizeof(sep_list));
	if (old == NULL)
		return (NULL);

	old->separator = sep;
	old->next = NULL;
	template = *head;

	if (template == NULL)
	{
		*head = old;
	}
	else
	{
		while (template->next != NULL)
			template = template->next;
		template->next = old;
	}

	return (*head);
}

/**
 * free_list - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_list(sep_list **head)
{
	sep_list *temp;
	sep_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *now, *temp;

	now = malloc(sizeof(line_list));
	if (now == NULL)
		return (NULL);

	now->line = line;
	now->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = now;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = now;
	}

	return (*head);
}

/**
 * free_line - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line(line_list **head)
{
	line_list *temp;
	line_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
