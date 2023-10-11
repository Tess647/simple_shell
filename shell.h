#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void _puts(char *c);
char _putchar(char c);
char *_strdup(const char *s);
void execute(char **argv);

#endif
