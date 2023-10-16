#include "shell.h"

/**
 * _strdup - function duplicated a string
 * @s: string to be duplicated
 * Return: On success, a pointer to the  duplicated  string
*/
char *_strdup(const char *s)
{
	char *string_dup;
	int i = 0, j;

	if (!s)
		return (NULL);

	while (s[i] != '\0')
	{
		i++;
	}
	i++;

	string_dup = malloc(sizeof(char) * i);


	if (!string_dup)
		return (NULL);

	for (j = 0; j < i - 1; j++)
	{
		string_dup[j] = s[j];
	}

	string_dup[j] = '\0';


	return (string_dup);
}

/**
 * _strlen - it gives the length of a string
 * @str: pointer to the string
 * Return: the length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @c: pointer to string
 */
void _puts(char *c)
{
	int i = 0;

	while (c[i])
	{
		_putchar(c[i]);
		i++;
	}
}
