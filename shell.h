#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **environ;

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **_strtok(char *str, const char *delim);
int _execute(char **argc);

#endif
