#include "shell.h"

/**
 *execute_command - Function to execute a command given a full path
 *@full_path: path of the command to be executed
 *@argv:double pointer to command
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
 *iterate_and_execute - Function to iterate through the path list
 *and execute the command
 *@argv: command to be executed
 *@path_list_head: pointer to the head of the linked list
 */
void iterate_and_execute(char **argv, path_list *path_list_head)
{
	path_list *current = path_list_head;
	char *directory, *full_path;

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
}

/**
  *execute - function to execute a command
  *@argv: command name to be executed
  *@path_list_head: pointer to the head of directory list
  */
void execute(char **argv, path_list *path_list_head)
{

	if (argv)
		iterate_and_execute(argv, path_list_head);

	/* Clean up memory */
	freeargv(argv);
}
