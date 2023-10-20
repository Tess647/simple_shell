#include "shell.h"

/**
 * main - main function for the shell program
 *
 * Return: 0 Always successful otherwise -1
 */

int main(void)
{
	char *cmdline = NULL;
	size_t n = 0;
	char **argv = NULL, *delim = " \n", *path, *pathname;
	int len = 0;
	path_list *head = '\0';
	void (*func)(char **);

	signal(SIGINT, signal_handler);

	while (len != EOF)
	{
		_isatty();
		len = getline(&cmdline, &n, stdin);
		_EOF(len, cmdline);

		argv = split_command_line(cmdline, delim);
		if (!argv || !argv[0])
			execute(argv);

		else
		{
			/* Parse PATH and create a linked list of directories */
			path = _getenv("PATH");
			head = add_nodes(path);
			pathname = _whichpath(argv[0], head);
			func = check_custom_build(argv);
			if (func)
			{
				free(cmdline);
				func(argv);
			}
			else if (!pathname)
				execute(argv);
			else if (pathname)
			{
				free(argv[0]);
				argv[0] = pathname;
				execute(argv);
			}
		}
	}
	free_list(head);
	freeargv(argv);
	free(cmdline);
	return (0);
}
