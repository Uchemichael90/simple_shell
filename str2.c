#include "shell.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *recent;
	size_t len;

	len = _strlen(s);
	recent = malloc(sizeof(char) * (len + 1));
	if (recent == NULL)
		return (NULL);
	_memorycpy(recent, s, len + 1);
	return (recent);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @sep: seprator.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *sep)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; sep[j]; j++)
		{
			if (str[i] == sep[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some seprator.
 * @str: input string.
 * @sep: seperator.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *sep)
{
	static char *split, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, sep))
			return (NULL);
		split = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = split;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *split; split++)
	{
		/*Breaking loop finding the next token*/
		if (split != str_start)
			if (*split && *(split - 1) == '\0')
				break;
		/*Replacing seprator for null char*/
		for (i = 0; sep[i]; i++)
		{
			if (*split == sep[i])
			{
				*split = '\0';
				if (split == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *split) /*Str != Sep*/
			bool = 1;
	}
	if (bool == 0) /*Str == sep*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
