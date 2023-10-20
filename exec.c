#include "shell.h"

/**
 * execute - Function to execute a command
 * @argv:double pointer to command
 */
void execute(char **argv)
{
	pid_t child_pid;

	if (!argv || !argv[0])
		return;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid error");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * _whichpath - Function finds the pathname of a file
 * @command: command name or filename
 * @head: head of linked list of path directories
 *
 * Return: pathname of filename
 * NULL on failure
 */
char *_whichpath(char *command, path_list *head)
{
	struct stat file_stat;
	char *string;

	path_list *temp_node = head;

	while (temp_node)
	{
		string = concatenate(temp_node->dir, "/", command);
		if (stat(string, &file_stat) == 0)
		{
			return (string);
		}
		free(string);
		temp_node = temp_node->pointer;
	}
	return (NULL);
}
