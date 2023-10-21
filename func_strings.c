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
 * concatenate - concats 3 strings in a newly allocated memory
 * @name: first string
 * @separator: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concatenate(char *name, char *separator, char *value)
{
	char *result;
	int name_len, sep_len, value_len, i, j;

	name_len = _strlen(name);
	sep_len = _strlen(separator);
	value_len = _strlen(value);

	result = malloc(name_len + sep_len + value_len + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	j = i;

	for (i = 0; separator[i]; i++)
		result[j + i] = separator[i];
	j = j + i;

	for (i = 0; value[i]; i++)
		result[j + i] = value[i];
	j = j + i;

	result[j] = '\0';

	return (result);
}

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t n;

	for (n = 0; src[n] != '\0'; n++)
		dest[n] = src[n];
	dest[n] = '\0';
	return (dest);
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
