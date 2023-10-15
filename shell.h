#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int _strlen(char *str);
void _puts(char *c);
int _putchar(char c);
char *_strdup(const char *s);

extern char **environ;

/**
 * struct path_list - Linked list containing PATH directories
 * @directory: dir in path
 * @pointer: pointer to next node
 */
typedef struct path_list
{
	char *dir;
	struct path_list *pointer;
} path_list;

path_list *add_nodes(char *path);
char *_getenv(const char *name);
void execute(char **argv, path_list *path_list_head);
#endif
