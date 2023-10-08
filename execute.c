#include "shell.h"

/**
 *  execute - function to execute commands
 *  @argv: pointer to pointer of argv string
 *
 *  Return: Nothing
 */

void execute(char **argv)
{
	pid_t child_pid = fork();
	char *command = NULL;
	int j;

	if (argv)
	{
		command = argv[0];

		if (child_pid == -1)
		{
			perror("fork_error");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(command, argv, NULL) == -1)
			{
				perror("execve_error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("waitpid_error");
				exit(EXIT_FAILURE);
			}
		}
	}

	for (j = 0; argv[j] != NULL; j++)
	{
		free(argv[j]);
	}
	free(argv);
}

