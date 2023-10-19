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
<<<<<<< HEAD
	int len;

=======
	int i = 0, argc = 0, len = 0;
>>>>>>> main
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
<<<<<<< HEAD
		argv = split_command_line(cmdline, delim);
		if (argv == NULL)
=======

		cmdline_copy = _strdup(cmdline);

		token = strtok(cmdline, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			argc++;
		}

		argv = malloc(sizeof(char *) * (argc + 1));

		token = strtok(cmdline_copy, delim);

		i = 0;

		while (token)
>>>>>>> main
		{
			return (-1);
		}

		execute(argv, head); /* execute command */
		func = check_custom_build(argv);
		if (func)
		{
			free(cmdline);
			func(argv);
		}
	}
<<<<<<< HEAD
	freeargv(argv);
	free(cmdline);
=======
	free(cmdline),free(cmdline_copy), freeargv(argv);
>>>>>>> main
	free_list(head);
	return (0);
}
