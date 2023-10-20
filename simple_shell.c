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
	char **argv = NULL, *delim = " \n";
	int len = 0;

	void (*func)(char **);

	signal(SIGINT, signal_handler);

	while (len != EOF)
	{
		_isatty();
		len = getline(&cmdline, &n, stdin);
		_EOF(len, cmdline);

		argv = split_command_line(cmdline, delim);
		if (argv == NULL)
			freeargv(argv);

		func = check_custom_build(argv);
		if (func)
		{
			free(cmdline);
			func(argv);
		}
		else
		{
			/* Parse PATH and create a linked list of directories */
			char *path = _getenv("PATH");
			path_list *head = add_nodes(path);

			execute(argv, head); /* execute command */
			free_list(head);
		}
	}
	freeargv(argv);
	free(cmdline);
	free_list(head);
	return (0);
}
