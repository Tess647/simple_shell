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

	string_dup = '\0';

	return (string_dup);
}
