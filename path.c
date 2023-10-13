#include "shell.h"

/**
  * add_nodes - adds directories in PATH as nodes to list
  * @path - pointer to PATH variable
  *
  * Return: pointer to head of linked list
  */
path_list *add_nodes(char *path)
{
	path_list *head = NULL;
	path_list *tail = NULL;
	path_list *newNode;

	//parse through PATH and split it into directories
	char *dir = strtok(path, ":");

	while (dir)
	{
		//create a new node for the directory
		newNode = malloc(sizeof(path_list));
		newNode->dir = strdup(dir);
		newNode->pointer = NULL;

		//add node to the list
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

		dir = strok(NULL, ":");
	}
	return (head);
}
