#include "shell.h"

/**
 * get_len - Get the lenght of a number.
 * @n: type int number.
 * Return: size of a number.
 */
int get_len(int n)
{
	unsigned int n1;
	int size = 1;

	if (n < 0)
	{
		size++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		size++;
		n1 = n1 / 10;
	}

	return (size);
}
/**
 * aux_itoa - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *aux_itoa(int n)
{
	unsigned int n1;
	int size = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (size + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + size) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	size--;
	do {
		*(buffer + size) = (n1 % 10) + '0';
		n1 = n1 / 10;
		size--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pin = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pin *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pin);
}
