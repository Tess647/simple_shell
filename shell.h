#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>

int _strlen(char *str);
void _puts(char *c);
int _putchar(char c);
char *_strdup(const char *s);

void signal_handler(int sig_num);
void _EOF(int len, char *cmdline);
void _isatty(void);

char **split_command_line(const char *cmdline, const char *delim);
void freeargv(char **argv);

extern char **environ;

/**
 * struct path_list - Linked list containing PATH directories
 * @dir: dir in path
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
void free_list(path_list *path_list_head);

/**
 * struct custom_build - pointer to function with corresponding buildin command
 * @code_name: buildin command
 * @func: execute the buildin command
 */
typedef struct custom_build
{
	char *code_name;
	void (*func)(char **);
} custom_build;

void my_exit(char **argv);
void env(char **argv __attribute__ ((unused)));
void(*check_custom_build(char **argv))(char **argv);

#endif
