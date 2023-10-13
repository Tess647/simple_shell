#include "shell.h"

char *_strdup(char *str);

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
 *_strdup - copies a string to a newly allocated space
 *@str: pointer to string
 *
 *Return: pointer to a new string on success
 *NULL on failure or if str = NULL
 */
char *_strdup(char *str)
{
	char *s;
	int len = 0;
	int i;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	s = malloc((len * sizeof(char)) + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		s[i] = str[i];
	return (s);
}
