#include "shell.h"

/**
 * my_exit - exits the shell without a return of status n
 * @argv: array of arguments
 */
void my_exit(char **argv)
{
	int n;

	if (argv[1])
	{
		n = _atoi(argv[1]);
		if (n <= -1)
			n = 2;

		freeargv(argv);
		exit(n);
	}

	freeargv(argv);
	exit(0);
}

/**
 * env - prints the current environment
 * @argv: array of arguments
 */
void env(char **argv __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
 * _atoi - converts a string into an integer
 * @str: pointer to a string
 * Return: the integer
 */
int _atoi(char *str)
{
	int i = 0, integer = 0, sign = 1;

	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}

	while ((str[i] > '0') && str[i] <= '9')
	{
		integer = (integer * 10) + (sign * (str[i] - '0'));
		i++;
	}

	return (integer);
}
