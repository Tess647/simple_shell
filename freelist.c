#include "shell.h"

/**
  *free_list - frees the path_list linked list
  *@path_list_head: pointer to the head of path_list
  */
void free_list(path_list *path_list_head)
{
	path_list *temp;

	while (path_list_head)
	{
		temp = path_list_head->pointer;
		free(path_list_head->dir);
		free(path_list_head);
		path_list_head = temp;
	}
}
