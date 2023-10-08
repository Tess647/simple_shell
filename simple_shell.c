#include "shell.h"

/**
 * main - main function for the shell program
 *
 * Return: 0 Always successful otherwise -1
 */

int main(void)
{
	char *cmdline = NULL, *cmdline_copy = NULL, *token = NULL;
	size_t n = 0;
	char **argv = NULL, *delim = " \n";
	int i = 0, argc = 0;

	while (1)
	{
		printf("#cisfun$ ");
		/* read from the user */
		if (getline(&cmdline, &n, stdin) == -1)
		{
			printf("\n");
			return (-1);
		}

		cmdline_copy = _strdup(cmdline);
		printf("%s\n", cmdline);

		token = strtok(cmdline, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			argc++;
		}

		argv = malloc(sizeof(char *) * argc);

		token = strtok(cmdline_copy, delim);

		i = 0;

		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;

		/* execute cmmand */
		execute(argv);

	}
	free(cmdline), free(cmdline_copy), free(argv);

	return (0);
}
