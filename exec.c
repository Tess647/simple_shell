#include "shell.h"

/**
 * execute_command - Function to execute a command given a full path
 * @full_path: path of the command to be executed
 * @argv:double pointer to command
 */
void execute_command(const char *full_path, char **argv)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(full_path, argv, NULL) == -1)
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
 *construct_full_path - Function construct a full path
 *by concatenating a directory and command
 *@directory: directory path
 *@command: command name
 *
 *Return: concatenated path on success
 *NULL on failure
 */
char *construct_full_path(char *directory, char *command)
{
	int dir_length, command_length, i, j;
	size_t len = 0;
	char *full_path;

	dir_length = _strlen(directory);
	command_length = _strlen(command);

	/*+2 for '/' and null terminator*/
	len = dir_length + command_length + 2;
	full_path = malloc(len);

	if (full_path == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < dir_length; i++)
	{
		full_path[i] = directory[i];
	}
	full_path[i] = '/';
	i++;

	for (j = 0; j < command_length; j++)
	{
		full_path[i + j] = command[j];
	}

	full_path[i + command_length] = '\0';

	return (full_path);
}

/**
  *execute - function to execute a command
  *@argv: command name to be executed
  *@path_list_head: pointer to the head of directory list
  */
void execute(char **argv, path_list *path_list_head)
{
	path_list *current = path_list_head;
	char *directory, *full_path;
	struct stat file_stat;

	if (stat(argv[0], &file_stat) == 0)
	{
		if (S_ISREG(file_stat.st_mode) &&
				(file_stat.st_mode & S_IXUSR))
		{
	/* Input is a regular file and is executable,execute it directly */
			execute_command(argv[0], argv);
			return;
			/* Explicitly marking the end of the function*/
		}
	}

	while (current)
	{
		directory = current->dir;
		full_path = construct_full_path(directory, argv[0]);
		if (access(full_path, X_OK) == 0)
		{
			execute_command(full_path, argv);
			free(full_path);
			break;
			/*Stop searching once command is found and executed*/
		}
		free(full_path);
		current = current->pointer;
	}
	/* Clean up memory */
	if (argv == NULL)
		freeargv(argv);
}
