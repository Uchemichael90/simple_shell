#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @pest: char pointer the destop of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *pest, const char *src)
{
	int k;
	int m;

	for (k = 0; pest[k] != '\0'; k++)
		;

	for (m = 0; src[m] != '\0'; m++)
	{
		pest[k] = src[m];
		k++;
	}

	pest[k] = '\0';
	return (pest);
}
/**
 * *_strcpy - Copies the string pointed to by src.
 * @pest: Type char pointer the destop of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *pest, char *src)
{

	size_t n;

	for (n = 0; src[n] != '\0'; n++)
	{
		pest[n] = src[n];
	}
	pest[n] = '\0';

	return (pest);
}
/**
 * _strcmp - Function that compares two strings.
 * @str: type str compared
 * @str2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *str, char *str2)
{
	int i;

	for (i = 0; str[i] == str2[i] && str[i]; i++)
		;

	if (str[i] > str2[i])
		return (1);
	if (str[i] < str2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accepted: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accepted)
{
	int i, k, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (k = 0; *(accepted + k) != '\0'; k++)
		{
			if (*(s + i) == *(accepted + k))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
