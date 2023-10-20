#include "shell.h"

/**
 * split_command_line - splits a string and
 * makes it an array of pointers to words
 * @cmdline: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */
char **split_command_line(const char *cmdline, const char *delim)
{
	char *cmdline_copy, *token, **argv;
	int max_args, i;

	cmdline_copy = _strdup(cmdline);
	if (cmdline_copy == NULL)
	{ /* Handle memory allocation error */
		return (NULL);
	}

	token = strtok(cmdline_copy, delim);
	max_args = 10;  /* Adjust this as needed */

	argv = malloc(sizeof(char *) * max_args);
	if (argv == NULL)
	{ /* Handle memory allocation error */
		free(cmdline_copy);
		return (NULL);
	}

	i = 0;

	while (token)
	{
		argv[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;

		/* Resize the argv array if necessary */
		if (i >= max_args)
		{
			max_args *= 2;
			argv = realloc(argv, sizeof(char *) * max_args);
		}
	}
	argv[i] = NULL;
	free(cmdline_copy);
	return (argv);
}

/**
 * freeargv - frees the array of pointers arv
 * @argv: array of pointers
 */

void freeargv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}

