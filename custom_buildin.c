#include "shell.h"

/**
 * my_exit - exits the shell without a return of status n
 */
void my_exit(char **argv)
{
	int i, n;

	if (argv[1])
	{
		n = atoi(argv[1]);
		if (n <= -1)
			n = 2;
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		exit(n);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
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
