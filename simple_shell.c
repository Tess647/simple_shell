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
	char **argv = NULL, *delim = " \n", **commands = NULL;
	int len = 0, i;
	char *delim1 = "|";

	/*Parse through PATH and create a linked list of directories*/
	char *path = _getenv("PATH");
	path_list *head = add_nodes(path);

	void (*func)(char **);

	signal(SIGINT, signal_handler);

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			_puts("#cisfun$ ");
			len = getline(&cmdline, &n, stdin);
			_EOF(len, cmdline);
			argv = split_command_line(cmdline, delim);

			if (argv == NULL)
				freeargv(argv);

			execute(argv, head); /* execute command */
			func = check_custom_build(argv);
			if (func)
			{
				free(cmdline);
				func(argv);
			}
			freeargv(argv);
		}
	}
	else
	{
		if (fgets(cmdline, sizeof(cmdline), stdin) != NULL)
		{
			cmdline[strcspn(cmdline, "\n")] = '\0';

			commands = split_command_line_2(cmdline, delim1);		
			if (commands == NULL)
				freeargv(commands);

			for (i = 0; commands[i] != NULL; i++)
			{
				argv = split_command_line(commands[i], delim);
				if (argv == NULL)		
					freeargv(argv);
		
				execute(argv, head);
				func = check_custom_build(argv);
				if (func)
				{
					free(cmdline);
					func(argv);
				}
				freeargv(argv);
			}
			freeargv(commands);
		}
	}

	freeargv(argv);
	free(cmdline);
	free_list(head);
	return (0);
}
