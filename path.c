#include "shell.h"

/**
  * add_nodes - adds directories in PATH as nodes to list
  * @path: pointer to PATH variable
  *
  * Return: pointer to head of linked list
  */
path_list *add_nodes(char *path)
{
	path_list *head = NULL;
	path_list *tail = NULL;
	path_list *newNode;

	/*parse through PATH and split it into directories*/
	char *dir = strtok(path, ":");

	while (dir)
	{
		/*create a new node for the directory*/
		newNode = malloc(sizeof(path_list));
		if (newNode == NULL)
			return (NULL);

		newNode->dir = _strdup(dir);
		newNode->pointer = NULL;

		/*add node to the list*/
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->pointer = newNode;
			tail = newNode;
		}

		dir = strtok(NULL, ":");
	}
	return (head);
}

/**
 * _strlen - it gives the length of a string
 * @str: pointer to the string
 * Return: the length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

