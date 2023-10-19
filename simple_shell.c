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
	int i = 0, argc = 0, len = 0;
	/*Parse through PATH and create a linked list of directories*/
	char *path = _getenv("PATH");
	path_list *head = add_nodes(path);
	void (*func)(char **);

	signal(SIGINT, signal_handler);

	while (len != EOF)
	{
		_isatty();
		len = getline(&cmdline, &n, stdin);
		_EOF(len, cmdline);

		cmdline_copy = _strdup(cmdline);

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
			argv[i] = _strdup(token);
			token = strtok(NULL, delim);
			i++;
		}

		execute(argv, head); /* execute command */
		func = check_custom_build(argv);
		if (func)
		{
			free(cmdline);
			func(argv);
		}

	}
	free(cmdline), free(cmdline_copy), free(argv);
	free_list(head);

	return (0);
}
